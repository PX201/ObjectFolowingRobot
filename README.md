# Human-Following and Remote-Controlled Robot  

## Description  
This project is a  robot that can switch between two modes:  
1. **Follow Mode:** The robot uses ultrasonic and IR sensors to follow a person or object.  
2. **Remote-Control Mode:** The robot can be manually controlled using an IR remote.  

This project is designed to explore robotics concepts and control mechanisms in a fun and engaging way.  

---

## Features  
- Autonomous movement to follow a person or object.  
- Remote control using an IR remote.  
- Switchable modes for flexibility in operation.  
- Smooth motor control for forward, reverse, and turning movements.  

---

## Components Needed  
- **Arduino Uno**  
- **IR Sensors (2x)** – For left and right edge detection.  
- **Ultrasonic Sensor (HC-SR04)** – For distance measurement.  
- **IR Receiver Module** – To decode remote control signals.  
- **DC Motors (2x or 4x)** – For movement.  
- **Motor Driver Module (L298N)**  
- **Power Supply**   
- **Wires and Breadboard**  
- **Chassis** for the robot.  

---

## How It Works  
### 1. Follow Mode:  
- The ultrasonic sensor measures the distance to the nearest object.  
- IR sensors help the robot align with the object.  
- The robot adjusts its movement to maintain an optimal distance.  

### 2. Remote-Control Mode:  
- Commands from an IR remote are decoded using the IR receiver.  
- The user can control the robot's movements, such as forward, reverse, left, right, and stop.  

### 3. Switching Between Modes:  
- A button press on the remote toggles between Follow Mode and Remote-Control Mode.  

---

## Wiring Diagram  
You can create the wiring based on the following components:  
- Connect the motors to the motor driver (L298N).  
- Attach the IR sensors and ultrasonic sensor to the respective pins on the Arduino.  
- Connect the IR receiver to the Arduino for remote control functionality.  

---

## Code  
The Arduino code for this project is written in C++ using the Arduino IDE. It includes:  
- Logic for handling ultrasonic and IR sensors.  
- IR remote signal decoding to handle user commands.  
- Functions for motor control (move, reverse, turn, stop).  

[View the Code Here]([https://github.com/PX201/ObjectFolowingRobot/edit/main/ObjectFolowingAndRemoteControllerRobot.uni)





