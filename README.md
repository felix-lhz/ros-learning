# Ros-Learning（WSL2+Ubuntu20.04）



##  1.准备工作（Preparation）

###### Books

[Books/Ros Leanring at main · felix-lhz/Books (github.com)](https://github.com/felix-lhz/Books/tree/main/Ros Leanring)

### 1.1 基本系统组件安装（Basic System Component Installation）

###### WSL2+Ubuntu

[windows11 安装WSL2全流程_win11安装wsl2-CSDN博客](https://blog.csdn.net/u011119817/article/details/130745551)

###### cuda11.8+cudnn8.8

[WSL2+ubuntu2004+cuda11.8+cudnn8.8开发环境搭建_wsl安装cudnn-CSDN博客](https://blog.csdn.net/pipupip/article/details/131405555)

###### Linux GUI

[使用 WSL 运行 Linux GUI 应用 | Microsoft Learn](https://learn.microsoft.com/zh-cn/windows/wsl/tutorials/gui-apps)

###### pytorch安装

[使用 WSL 运行 Linux GUI 应用 | Microsoft Learn](https://learn.microsoft.com/zh-cn/windows/wsl/tutorials/gui-apps)

###### miniconda安装

[Miniconda — Anaconda documentation](https://docs.anaconda.com/miniconda/)

<img src=".\img\miniconda-download.png" style="zoom:50%;" />

### 1.2 工作空间（WorkSpace）

#### 1.2.1 工作空间配置（workspace config）

```创建WorkSpace
mkdir ~/p ~/ros-learning/src
cd ~/ros-learning/src
catkin_init_workspace
```

```catkin_make
cd ~/ros-learning
catkin_make
```

##### 1.2.1.1 catkin_make Errors

```catkin_make error  1
-- Could NOT find PY_em (missing: PY_EM) 
CMake Error at cmake/empy.cmake:30 (message):
Unable to find either executable 'empy' or Python module 'em'...  try
installing the package 'python-empy'
```

``` catkin_make error 2
ImportError: "from catkin_pkg.package import parse_package" failed: No module named 'catkin_pkg'
Make sure that you have installed "catkin_pkg", it is up to date and on the PYTHONPATH
```

[Ubuntu20.04安装Ros Noetic版本，在catkin_make编译时出现的问题_unable to find either executable 'empy' or python -CSDN博客](https://blog.csdn.net/qq_39437730/article/details/118272390#:~:text=-- Could N)

##### 1.2.1.2 locate error

WSL2安装locate命令一直显示Initializing mlocate database; this may take some time，进度一直卡在60%。

[WSL2安装locate命令一直显示Initializing mlocate database； this may take some time，进度一直卡在60%_initializing plocate database; this may take some -CSDN博客](https://blog.csdn.net/qq_15969343/article/details/129189584#:~:text=再次运行sudo a)

##### 1.2.1.3 环境变量配置

```source
echo "source ~/ros-learning/devel/setup.bash">>~/.bashrc
```

#### 1.2.2 功能包配置（package config）

``` create packages
cd ~/ros-learning/src
catkin_create_pkg learning_communication std_msgs rospy roscpp
cd ..
catkin_make
```

### 1.3 Vscode+ROS配置

[【ROS】VSCODE + ROS 配置方法（保姆级教程，总结了多篇）_vscode ros-CSDN博客](https://blog.csdn.net/g944468183/article/details/123759886#:~:text=使用VScode搭建)

## 2.ROS基础（ROS Basics）

### 2.1 话题中的Publisher与Subscriber（Publisher And Subscriber In Topic）

#### 2.1.1 创建Publisher（Create Publisher）

[talker.cpp](./src/learning_communication/src/talker.cpp)

#### 2.1.2 创建Subscriber（Create Subscriber）

[listener.cpp](./src/learning_communication/src/listener.cpp)

#### 2.1.3 CMakeList.txt

``` CMakeList.txt
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker_node src/talker.cpp)
add_executable(listener_node src/listener.cpp)

add_dependencies(talker_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(listener_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(talker_node
  ${catkin_LIBRARIES}
)
target_link_libraries(listener_node
  ${catkin_LIBRARIES}
)
```

#### 2.1.4 运行Publisher和Subscriber

```Run
catkin_make
roscore
rosrun learning_communication talker_node
rosrun learning_communication listener_node
```

#### 2.1.5 自定义消息包（msg）

[Person.msg](./src/learning_communication/msg/Person.msg)

###### 编译消息包（build msg）

```package.xml
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>
```

```CMakeList.txt
find_package(catkin REQUIRED COMPONENTS
  ......
  message_generation
)
catkin_package(
......
 CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs message_runtime
......
)
add_message_files(
  FILES
  Person.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
)
```

###### 查看消息包（check msg）

```terminal
rosmsg show Person
```

### 2.2 服务中的Server和Client（Server and Client in Service）

#### 2.2.1 定义服务数据（Defining Service Data）

[addTwoInts.srv](./src/learning_communication/srv/addTwoInts.srv)

```CMakeList.txt
# 其他配置已在2.1.5完成
add_service_files(
  FILES
  addTwoInts.srv
)
```

#### 2.2.2 Server and Client

[server.cpp](./src/learning_communication/src/server.cpp)

[client.cpp](./src/learning_communication/src/client.cpp)

```CMakeList.txt
add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

add_dependencies(server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(server
  ${catkin_LIBRARIES}
)
target_link_libraries(client
  ${catkin_LIBRARIES}
)
```

#### 2.2.3 运行Server和Client

```terminal
catkin_make
roscore
rosrun learning_communication server
rosrun learning_communication client 3 5
```



## 3 ROS中的常用组件

### 3.1 launch启动文件

```launch文件属性设置
# 常用属性
pkg：节点所在的功能包的名称	
name：节点名称
type：节点的可执行文件名称

# Others
output = "screen":将节点的标准输出打印到终端屏幕，默认输出为日志文档
respawn = "true":复位属性，该节点停止时，会自动重启，默认为false
required = "true":必要节点，该节点终止时，launch文件中的其他节点也被终止
ns = "namespace":命名空间，为节点内的相对名称添加命名空间前缀
args = "arguments":节点需要的输入参数
```

```launch文件参数设置
<param> 
<arg>
<remap>:重映射指令话题
<include>:嵌套服用，
```

### 4.2 TF坐标变换

坐标系变换：平移+旋转，4×4矩阵（齐次矩阵）

#### 4.2.1 TF工具

##### 4.2.1.1 tf_monitor

打印TF树中所有坐标系的发布状态。

```
查看指定坐标系之间的发布状态
th_echo <source_frame> <target_frame>
```

##### 4.2.1.2 tf_echo

查看指定坐标系之间的坐标系变化。

```
th_echo <source_frame> <target_frame>
```

##### 4.2.1.3 static_transform_publisher

发布两个坐标系之间的静态坐标变换，这两个坐标系不发生相对位置变化

```
# yaw:围绕z轴的偏航角，pitch:围绕y轴旋转的俯仰角，roll:围绕x轴旋转的翻滚角
static_transform_publisher x y z yaw pitch roll frame_id child_frame_id 
# 四元数
static_transform_publisher x y z qx qy qz qw frame_id child_frame_id 
```

##### 4.2.1.4 view_frames

可视化的调试工具，可以生成pdf文件，显示整棵TF树的信息。

#### 4.2.2 turtle_tf

[turtle_tf_broadcaster.cpp](./src/learning_tf/src/turtle_tf_broadcaster.cpp)

[turtle_tf_listener.cpp](src/learning_tf/src/turtle_tf_listener.cpp)

[start_demo_with_listener.launch](src/learning_tf/launch/start_demo_with_listener.launch)

!!! 修改CMakeList.txt and package.xml
