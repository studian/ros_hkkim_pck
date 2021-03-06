### 1. ros ws compile

##### 1) in \ros_ws
```
$ rm -rf build/ devel/
```
##### 2) in \ros_ws\src
```
$ rosws update
```
##### 3) in \ros_ws
```
$ catkin_make
```

### 2. ros run
```
$ roscore
```

### 3. ros play
##### 1)ros play just one time
```
$ rosbag play _2020-09-23-17-08-50.bag
```
##### 2) ros play and replay all
```
$ rosbag play -l _2020-09-23-17-08-50.bag
```

### 4. ros node run
##### 1) `python` based node run
```
$ rosrun ros_hkkim_pck py_image_subscriber.py
```
##### 2) `c++` based node run
```
$ rosrun ros_hkkim_pck image_subscriber_viewer
```

### 5. Ouster rosbag replay
##### 1) Execute viewer (point cloud and intensity images): `roslaunch ouster_ros os1.launch`
```
roslaunch ouster_ros os1.launch replay:=true viz:=true image:=true metadata:=/home/msp/ROS_data/sample_config_file.json
```
##### 2) ros play and replay all
```
rosbag play --clock -l _2020-09-23-17-08-50.bag
```


### 4. ros node run
##### 1) `python` based node run
```
$ rosrun ros_hkkim_pck py_image_subscriber.py
```
##### 2) `c++` based node run
```
$ rosrun ros_hkkim_pck image_subscriber_viewer
```

### 5. Ouster rosbag replay
##### 1) Execute viewer (point cloud and intensity images): `roslaunch ouster_ros os1.launch`
```
roslaunch ouster_ros os1.launch replay:=true viz:=true image:=true metadata:=/home/msp/ROS_data/sample_config_file.json
```
##### 2) ros play and replay all
```
rosbag play --clock -l _2020-09-23-17-08-50.bag
```


### 6. Ouster rosbag replay(2)
##### 1) Execute viewer (point cloud and intensity images): `roslaunch ouster_ros os1.launch`
```
roslaunch ouster_ros os1.launch replay:=true image:=true metadata:=/home/msp/ROS_data/sample_config_file.json
```
##### 2) ros play and replay all
```
rosbag play _2020-09-23-17-08-50.bag --clock -l
```

##### 3) ros run realsense rgb play
```
rosrun ros_hkkim_pck image_subscriber_viewer
```

##### 4) ros run ouster lidar intensity gray play
```
rosrun ros_hkkim_pck ouster_lidar_intensity_view
```

