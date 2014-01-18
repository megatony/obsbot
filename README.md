
Eskişehir Osmangazi University

Introduction to Microcomputers







Project Report


Robot Control with Obstacle Detection 


Group: < 1 >

151220104003 Bahadır Akın Akgül 
151220104008 Rasih Arıkan 
151220104050 Göksenin Güngör
151220114101 Emre Uzer








2013-2014 Fall Semester


1.	Introduction
In recent years many manufacturer produce mobile robots which are controllable autonomously. The more complex a robot’s working place gets the more complicated its obstacle detection and avoidance facilities need to designed. First of all, sensor equipment must be appropriate for the requirements of given scenarios. In many cases a lots of sensors have a limited field of vision and because of that reason may not be able to cover the all area around our device. One possibility to overcome this limitation is mounting several devices of the same kind. However, this leads to higher weight and costs and the evaluation of more data might exceed the computational capacity.
In this project, our robot senses any obstacle in its path, avoids it and resumes its running. Involves the pre-computation of an obstacle-free path which a controller guides the robot.
2.	Literature Review 
Schafer notes that “We presented an approach for virtually extending the coverage of obstacle detection sensor systems. The formulated algorithm uses information about the vehicle motion to propagate sensor data into the blind zone of the robot. Due to a massive reduction of stored data the system features low memory usage. Additionally there is no need for calculating the correspondence between consecutive data making the approach applicable for realtime scenarios. Next steps involve the integration of a stereo camera system. Due to the device’s limited field of view the presented algorithm leads to an eminent extension of the supervised area surrounding the vehicle. Additionally the accuracy of the local positioning system will be enhanced by visual ego motion estimation.”
On the other hand, Montiel notes that “In this work was shown the design of an stereoscopic vision module for a wheeled mobile robot, suitable to be implemented into an FPGA. The main purpose of the onboard system of the MR is to provide the necessary elements for perception, obstacles detection, map building and map reconfiguration in a tough environment where there are no landmarks or references. The stereoscopic vision system captures left and right images from the same MR scene, the system is capable of using both appearance based pixel descriptors for surface ground extraction, luminance or Hue depending of the environment particular characteristics. In an environment with constant lightness, minimum reflections and proper setting in the edge detector threshold level, luminance can be suitable because surface ground and obstacles edge detection can be performed at the same time. For environment with variable light conditions or uncertain, Hue is the primary attribute for pixel appearance descriptor in the surface ground extraction process due to its invariance to changes in luminance and color saturation. After surface ground extraction and obstacles edge detection, stereoscopic corresponding by block matching is performed, the correspondence is found among a set of points in the left and right images by using a feature based approach. Disparity computation for the matched points is then performed. Establishing correspondences between point locations in images acquired from multiple views (matching) is one of the key tasks in the reconstruction based on stereo image analysis. This feature based approach, involves detecting the feature points and tracking their positions in multiple views of the environment. Stereoscopic camera calibration is not required due to the improvements in matching process. Disparity maps which are the depth measure of the obstacles position in the environment are obtained after the stereo correspondence process. The MR sends this data, including its position and orientation via RF to the global planner located in the main computer outside the environment. With this information the global planner is able to constantly update the environment map.”
3.	Implementation of the System
 Our project team are discussed and decided to use infrared sensor that called Sharp GP2D120. Because, we are able to simulate it on our ISIS simulation easily. Infrared sensor can be simulated in ISIS. On the other hand, we have to use integrating analog digital converter ADC0804 to take information from it and use it in our microcontroller Intel 8051.
In our design, we also use 4 leds to follow actual state of our circuitrary with easy way:
When you see BLUE LED blinking, it means that processor gets the digital input form P2 than starts to comparing. 

When you see RED LED blinking, it means robot is in 10 cm behavior. When sensor range at equal or less than 10 cm, robot goes to reverse direction. When sensor range at 10 cm ADC produces binary 10001011 = 139. We control whole P2 port in if statement with "BII >= 139".

When you see YELLOW LED blinking, it means robot is in between 10 cm and 20 cm behavior. When sensor range at 20 cm ADC produces binary 01001001 = 73, robot goes to forward direction. We control whole P2 port in if statement with "BII < 139 & BII >= 73".

When you see GREEN LED blinking, it means robot is in between 20 cm and 30 cm behavior. Robot goes to forward direction. When sensor range at 20cm ADC produces binary 00110011 = 73. We control whole P2 port in if statement with "BII < 139 & BII >= 73".

Of course there are also some code to control ADC and DC motors. In this step, we just look up to datasheets of these elements and write it our code according to that. 



5.	Result and Conclusion

In the project proposal, we design our system to avoiding obstacles. In this process, we were taking only presence of obstacle. In the first design, we are taking this information and our robot will behave according to that. After the consulting process with our project assistant and our project advisor, we are going to add a feature to it. This feature was behaving according to proximity of obstacles. 

They advised us two sensor type: ultrasonic sensor and infrared sensor. Our project team are discussed and decided to use infrared sensor that called Sharp GP2D120 to easily simulate it on simulation. On the other hand, we have to use integrating analog digital converter ADC0804 to take information from it and use it in our microcontroller Intel 8051. It works properly.

In our previous design, we can not simulate our circuitrary properly. We investigate to find error and finally we found. Simulation was not work properly becuse we didn’t use ADC with interrupt. When ADC still working, we are going to try do something in our system. After that, we realize that, with the rising edge of W (from 0 to 1) ADC0804 starts conversion process. After conversion done ADC0804 produce low signal at ~INTR that means conversion done. If data is ready P2(means ~INTR=0) starts comparing process.

In this project, most of us are worked as a team firstly. We think it’s the most important thing what we learnt from this project. Addition to that, we clearly understand how Intel 8051 behaves. Because, we tried many things on it and it’s a good way to learn. Then, we learnt how a infrared sensor works. Some of us doesn’t know it or know it differently. Finally, it was a great project for us to applying our theoritical knowledge to a real life project and it was a great inspiration for us to our future projects.






























References

H. Schafer, M. Proetzsch, K. Berns, Obstacle Detection in Mobile Robots, Robotics Research Lab, University of Kaiserslautern, P.O. Box 3049, D-67653 Kaiserslautern, Germany.

Oscar Montiel, Alfredo González and Roberto Sepúlveda, Vision Based Obstacle Detection
Module for a Wheeled Mobile Robot, Centro de Investigación y Desarrollo de Tecnología Digital
del Instituto Politécnico Nacional México.

Bonnafous, D., Lacroix, S., and Simon, T. (2001). Motion generation for a rover on rough terrain. In IEEE/RSJ International Conference on Intelligent Robots and Systems.

Schafer, H. and Berns, K. (2006). Ravon - an autonomous vehicle for risky intervention and surveillance. In International Workshop on Robotics for risky intervention and environmental surveillance - RISE.

Dilmen, E., Parlaktuna, O., Yazici, A., "A novel sonar-based obstacle detection approach sensor-based coverage problem," Electrical and Electronics Engineering, 2009. ELECO 2009. International Conference on , vol., no., pp.II-366,II-369, 5-8 Nov. 2009

