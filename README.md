# Robotics_HNDSE_Repo

# Pet Care Robot - Robotics Module Project

**University:** National Institute of Buisness Management
**Module:** Robotics
**Year:** 2nd Year
**Group Members:**
* A.H.V.M Jayarathne
* Uvindu Sankalpa Weerasooriya
* M.K.D Gangadara
* Thusathmi Sapumanage

## Project Overview

This project involved the design and implementation of an autonomous pet care robot. The robot is designed to assist in the daily care of a pet by automating tasks such as food and water replenishment, litter box management, and interactive playtime. This project was undertaken as part of the Robotics module in our second year of university.

## Functionality

The pet care robot incorporates the following key functionalities:

* **Pet Proximity Sensing:** Detects the presence of the pet within a defined range.
* **Automated Food and Water Dispensing:**
    * Monitors the levels of food and water in designated bowls.
    * Refills the bowls automatically when the levels fall below a preset threshold.
* **Automated Litter Box Management:**
    * Features an embedded litter box that extends when the pet is nearby.
    * After use (simulated), the robot automatically transfers used litter to a separate storage compartment.
    * The litter box then retracts.
* **Interactive Playtime:**
    * **Ball Throwing:** Launches small, non-harmful balls for the pet to chase.
    * **Laser Pointing:** Projects a non-harmful laser pointer that moves in random directions to engage the pet.
* **Scheduled Activities:**
    * Playtime sessions (ball throwing and laser pointing) are triggered by preset alarms using a Real-Time Clock (RTC) module.
* **Power Source:** The robot is powered via a wall outlet.

## Hardware Components

The robot utilizes the following key hardware components:

* **Microcontrollers:** 2 x Arduino Uno
    * One Arduino primarily manages sensor input (pet proximity, food/water levels), dispensing mechanisms.
    * The second Arduino controls the litter box control and interactive playtime features (ball launcher, laser pointer) and interfaces with the RTC module.
* **Sensors:**
    * Proximity sensor (e.g., Infrared (IR) sensor or Ultrasonic sensor) to detect the pet's presence.
    * Level sensors (e.g., float switches or capacitive sensors) to monitor food and water levels.
* **Actuators:**
    * Servo motors and Solonoid valves with drivers for food and water dispensing mechanisms.
    * Customized DC gear motor for extending and retracting the litter box.
    * Motor and mechanism for the ball launcher.
    * Servo motors for controlling the direction of the laser pointer.
* **Real-Time Clock (RTC) Module:** Used for scheduling playtime activities.
* **Power Supply:** AC-DC adapter to power the Arduino boards and actuators.
* **Structural Components:** Chassis and enclosures made from materials such as Aluminium L bars, Wood, Aluminium sheets.
* **Litter Box Mechanism:** Includes a small container for litter, a mechanism for extension/retraction, and a separate compartment for waste.
* **Ball Launcher Mechanism:** A device capable of launching small balls (Table tennis size) a short distance.
* **Laser Pointer Module:** A low-power, non-harmful laser diode.

## Software Implementation

The software for the robot was developed using the Arduino IDE and primarily consists of:

* **Arduino Sketches:** Separate programs written for each of the two Arduino Uno boards.
    * ** Arduino board1 :** Code to read sensor data, control dispensers.
    * ** Arduino board2 :** Code to manage the Litter mechanism, ball launcher and laser pointer movements based on RTC alarms and potentially input from the main Arduino.
* **Libraries:** Utilized relevant Arduino libraries for sensor interfacing, motor control, and RTC communication (e.g., `Servo.h`, specific sensor libraries, `RTClib.h`).

## Challenges and Solutions

During the development of this project, we encountered several challenges, including:

* **Interfacing multiple sensors and actuators with limited microcontroller pins:** This was addressed by using two microcontrollers and effectively managing which components to be used (eg: l198N over l293d)
* **Designing a reliable and compact litter box mechanism:** [Mention design considerations and solutions].
* **Ensuring the safety of the laser pointer for the pet:** Strict measures were taken to use a low-power laser and implement random movement patterns to avoid prolonged direct exposure.


## Future Improvements

Possible future improvements for this project include:

* **Integration of a camera and mobile app control:** Allowing remote monitoring and control of the robot.
* **More sophisticated pet activity recognition:** Using machine learning to understand the pet's behavior and tailor interactions accordingly.
* **Automatic cleaning of the litter box waste compartment.**
* **Voice control for initiating specific actions.**
* **Wireless charging capability.**
* **Improved obstacle avoidance for robot mobility (if the robot were to be mobile in future iterations).**

## Conclusion

This pet care robot project provided us with valuable hands-on experience in robotics, embedded systems programming, sensor integration, and mechatronics design. It demonstrated our ability to work collaboratively to conceive, design, and implement a complex system using Arduino microcontrollers. We are proud of the functionality achieved and the lessons learned throughout this project.
