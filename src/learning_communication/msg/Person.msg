# Standard metadata for higher-level flow data types
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