# Ros-Learning（WSL2+Ubuntu20.04）



##  1.准备工作（Preparation）

###### Books

[ROS机器人开发实践 (机器人设计与制作系列)【文字版】 (胡春旭)](./PDF/ROS机器人开发实践 (机器人设计与制作系列)【文字版】 (胡春旭).pdf)

[ROS机器人开发：实用案例分析（原书第2版）](./PDF/ROS机器人开发：实用案例分析（原书第2版）.pdf)

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

[talker.cpp](./src/learning_communication/src/talk.cpp)

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

