# Arduino Remote Control Ping Pong Launcher
This project is an Arduino-based remote control ping pong launcher. It utilizes various types of motors to create a fun and interactive experience.

![CAD Demo](https://i.ibb.co/t3cv2zZ/Ping-Pong-Ball-Launcher.png)

## Requirements
-   Arduino board
-   IR remote
-   Stepper motor
-   Servo motor
-   LED
-   Jumper wires
-   Breadboard

## Libraries
This project uses the following libraries:

-   `IRremote.h`
-   `Stepper.h`
-   `Servo.h`

## Wiring
The wiring diagram for this project is as follows:

-   IR receiver is connected to pin 7 of the Arduino board.
-   Stepper motor is connected to pins 2, 4, 3, and 5 of the Arduino board.
-   Servo motor is connected to pin 6 of the Arduino board.
-   LED is connected to pin 8 of the Arduino board.


Code Explanation
----------------

## IR Remote

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


## Functionality

-   The launcher uses stepper and servo motors to launch a ping pong ball with precision.
-   The IR remote allows the user to control the launcher's movements and timing of launch.
-   The LED serves as an indicator, signaling when the launcher is ready to fire.

## Assembly Instructions

-   Connect the IR receiver, stepper motor, servo motor, and LED to the Arduino board according to the wiring diagram.
-   Upload the code to the Arduino board.
-   Mount the launcher and load the ping pong ball.

## Troubleshooting

-   Check the wiring connections.
-   Ensure the correct libraries are installed and the code is uploaded correctly.
-   Verify the battery life of the remote.

## Customization

-   Add additional features such as sensors or automatic reloading mechanisms.
-   Change the design of the launcher to fit specific needs.
-   Use different components to enhance or modify the functionality of the launcher.

Future Improvements:

-   Add sensors to detect when the ping pong ball is launched.
-   Integrate Bluetooth or Wi-Fi connectivity to control the launcher remotely.
-   Incorporate voice control for a more interactive experience.


## License
*MIT License*

*Copyright (c) [2022] [EntrepreneurBrad]*

*Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:*

*The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.*

*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*
