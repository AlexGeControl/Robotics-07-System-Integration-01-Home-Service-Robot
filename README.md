# Deep Reinforcement Learning Arm Manipulation

[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

[//]: # (Written by Ge Yao, 8th, April, 2019)

This project aims to create a home service robot solution from scratch to illusrate the end-to-end work flow for robotics development. Including tasks are follows:

* Define Environment using Shell Scripts
* 

---

```xml
    <!-- map update frequency -->
    <param name="lskip" value="10"/>

    <!-- map update frequency -->
    <param name="linearUpdate" value="0.10"/>
    <param name="angularUpdate" value="0.10"/> 

    <!-- the initial map size -->
    <param name="particles" value="128"/> 
	
    <!-- the initial map size -->
    <param name="xmin" value="-10.0"/>
    <param name="ymin" value="-10.0"/>
    <param name="xmax" value="+10.0"/>
    <param name="ymax" value="+10.0"/>
```

---

```shell
# save map:
rosrun map_server map_saver -f home.pgm
```

---