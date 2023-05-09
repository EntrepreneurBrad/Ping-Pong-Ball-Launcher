Arduino Remote Control Ping Pong Launcher
=========================================

This project is an Arduino-based remote control ping pong launcher. It utilizes various types of motors to create a fun and interactive experience.

Requirements
------------

-   Arduino board
-   IR remote
-   Stepper motor
-   Servo motor
-   LED
-   Jumper wires
-   Breadboard

Libraries
---------

This project uses the following libraries:

-   `IRremote.h`
-   `Stepper.h`
-   `Servo.h`

Wiring
------

The wiring diagram for this project is as follows:

-   IR receiver is connected to pin 7 of the Arduino board.
-   Stepper motor is connected to pins 2, 4, 3, and 5 of the Arduino board.
-   Servo motor is connected to pin 6 of the Arduino board.
-   LED is connected to pin 8 of the Arduino board.

Code Explanation
----------------

### IR Remote

The IR remote is used to control the launcher. The `IRremote` library is used to decode the signals from the remote. The following buttons on the remote are used:

| Button | Identifier |
| --- | --- |
| Mode | 16736925 |
| ->> | 16761405 |
| -<< | 16712445 |
| + | 16748655 |
| - | 16754775 |
| 0 | 16738455 |
| 1 | 16724175 |
| 2 | 16718055 |
| 3 | 16743045 |
| 4 | 16716015 |
| 5 | 16726215 |

### Stepper Motor

The stepper motor is used to control the angle of the launcher. The `Stepper` library is used to control the stepper motor. The `stepsPerRevolution` variable is set to 2048, which is the number of steps per revolution. The `stepper` object is created with pins 2, 4, 3, and 5 of the Arduino board. The `stepsMadeCounter` variable is used to keep track of the location of the stepper, so it does not go too far in either direction. The `stepsDif` variable allows for the integration of the potentiometer with the stepper. The `autoFuncWorking` variable tracks if the auto function has been turned on or off by the user. The `isModePressed` variable is used instead of a digital read button. The `target` variable is the initial value for the stepper to work towards in the auto function.

### Servo Motor

The servo motor is used to launch the ping pong ball. The `Servo` library is used to control the servo motor. The `servo` object is created and attached to pin 6 of the Arduino board. The `servoAngle` variable is used to store the servo position. The `speedAdjust` variable allows for the rate of fire to be variable. The `servoOff` variable manages if the servo has been asked to come off. The `servoOn` variable manages if the servo has been asked to come on. The `pause` variable allows for the execution of the servo motor without taking too much time out of other accessories. The `letsBeginFunc` variable allows for the first stage to occur without trouble the second time around. The `goingUp` variable allows the servo function to sense if it needs to increase or decrease in degrees. The `goingDown` variable allows the servo function to sense if it needs to increase or decrease in degrees. The `weAreDone` variable tells when the rotation is done. The `waitingTime` variable is used to allowArduino Remote Control Ping Pong Launcher
=========================================

This project is an Arduino-based remote control ping pong launcher. It utilizes various types of motors to create a fun and interactive experience.

Requirements
------------

-   Arduino board
-   IR remote
-   Stepper motor
-   Servo motor
-   LED
-   Jumper wires
-   Breadboard

Libraries
---------

This project uses the following libraries:

-   `IRremote.h`
-   `Stepper.h`
-   `Servo.h`

Wiring
------

The wiring diagram for this project is as follows:

-   IR receiver is connected to pin 7 of the Arduino board.
-   Stepper motor is connected to pins 2, 4, 3, and 5 of the Arduino board.
-   Servo motor is connected to pin 6 of the Arduino board.
-   LED is connected to pin 8 of the Arduino board.

Code Explanation
----------------

### IR Remote

The IR remote is used to control the launcher. The `IRremote` library is used to decode the signals from the remote. The following buttons on the remote are used:

| Button | Identifier |
| --- | --- |
| Mode | 16736925 |
| ->> | 16761405 |
| -<< | 16712445 |
| + | 16748655 |
| - | 16754775 |
| 0 | 16738455 |
| 1 | 16724175 |
| 2 | 16718055 |
| 3 | 16743045 |
| 4 | 16716015 |
| 5 | 16726215 |

### Stepper Motor

The stepper motor is used to control the angle of the launcher. The `Stepper` library is used to control the stepper motor. The `stepsPerRevolution` variable is set to 2048, which is the number of steps per revolution. The `stepper` object is created with pins 2, 4, 3, and 5 of the Arduino board. The `stepsMadeCounter` variable is used to keep track of the location of the stepper, so it does not go too far in either direction. The `stepsDif` variable allows for the integration of the potentiometer with the stepper. The `autoFuncWorking` variable tracks if the auto function has been turned on or off by the user. The `isModePressed` variable is used instead of a digital read button. The `target` variable is the initial value for the stepper to work towards in the auto function.

### Servo Motor

The servo motor is used to launch the ping pong ball. The `Servo` library is used to control the servo motor. The `servo` object is created and attached to pin 6 of the Arduino board. The `servoAngle` variable is used to store the servo position. The `speedAdjust` variable allows for the rate of fire to be variable. The `servoOff` variable manages if the servo has been asked to come off. The `servoOn` variable manages if the servo has been asked to come on. The `pause` variable allows for the execution of the servo motor without taking too much time out of other accessories. The `letsBeginFunc` variable allows for the first stage to occur without trouble the second time around. The `goingUp` variable allows the servo function to sense if it needs to increase or decrease in degrees. The `goingDown` variable allows the servo function to sense if it needs to increase or decrease in degrees. The `weAreDone` variable tells when the rotation is done. The `waitingTime` variable is used to allow
