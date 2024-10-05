;; Auto-generated. Do not edit!


(when (boundp 'learning_communication::Person)
  (if (not (find-package "LEARNING_COMMUNICATION"))
    (make-package "LEARNING_COMMUNICATION"))
  (shadow 'Person (find-package "LEARNING_COMMUNICATION")))
(unless (find-package "LEARNING_COMMUNICATION::PERSON")
  (make-package "LEARNING_COMMUNICATION::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(intern "*UNKNOWN*" (find-package "LEARNING_COMMUNICATION::PERSON"))
(shadow '*UNKNOWN* (find-package "LEARNING_COMMUNICATION::PERSON"))
(defconstant learning_communication::Person::*UNKNOWN* 0)
(intern "*MALE*" (find-package "LEARNING_COMMUNICATION::PERSON"))
(shadow '*MALE* (find-package "LEARNING_COMMUNICATION::PERSON"))
(defconstant learning_communication::Person::*MALE* 1)
(intern "*FEMALE*" (find-package "LEARNING_COMMUNICATION::PERSON"))
(shadow '*FEMALE* (find-package "LEARNING_COMMUNICATION::PERSON"))
(defconstant learning_communication::Person::*FEMALE* 2)

(defun learning_communication::Person-to-symbol (const)
  (cond
        ((= const 0) 'learning_communication::Person::*unknown*)
        ((= const 1) 'learning_communication::Person::*male*)
        ((= const 2) 'learning_communication::Person::*female*)
        (t nil)))

(defclass learning_communication::Person
  :super ros::object
  :slots (_seq _stamp _frame_id _name _sex _age ))

(defmethod learning_communication::Person
  (:init
   (&key
    ((:seq __seq) 0)
    ((:stamp __stamp) (instance ros::time :init))
    ((:frame_id __frame_id) "")
    ((:name __name) "")
    ((:sex __sex) 0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _seq (round __seq))
   (setq _stamp __stamp)
   (setq _frame_id (string __frame_id))
   (setq _name (string __name))
   (setq _sex (round __sex))
   (setq _age (round __age))
   self)
  (:seq
   (&optional __seq)
   (if __seq (setq _seq __seq)) _seq)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:frame_id
   (&optional __frame_id)
   (if __frame_id (setq _frame_id __frame_id)) _frame_id)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; uint32 _seq
    4
    ;; time _stamp
    8
    ;; string _frame_id
    4 (length _frame_id)
    ;; string _name
    4 (length _name)
    ;; uint8 _sex
    1
    ;; uint8 _age
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _seq
       (write-long _seq s)
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; string _frame_id
       (write-long (length _frame_id) s) (princ _frame_id s)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;; uint8 _age
       (write-byte _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _seq
     (setq _seq (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _frame_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _frame_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get learning_communication::Person :md5sum-) "2b5036ffcd5ffec582107f797dde5f8a")
(setf (get learning_communication::Person :datatype-) "learning_communication/Person")
(setf (get learning_communication::Person :definition-)
      "# Standard metadata for higher-level flow data types
uint32 seq # Sequence number
time stamp # Timestamp of the message
string frame_id # ID of the associated coordinate frame

# Person.msg
string name
uint8 sex
uint8 age

uint8 unknown = 0
uint8 male = 1
uint8 female = 2
")



(provide :learning_communication/Person "2b5036ffcd5ffec582107f797dde5f8a")


