#include <IRremote.h> //importing libraries
#include <Stepper.h>
#include <Servo.h>


//ir remote

int irReciever = 7; //pin with the infra-red reciever

IRrecv irrecv(irReciever); //declaring that the pin is infact the pin to monitor ir

decode_results results; //declaring 'results'

#define mode 16736925 // identifier of the 'Mode' button
#define forwards 16761405 // identifier of the '->>' button
#define backwards 16712445 // identifier of the '-<<' button
#define plus 16748655 // identifier of the '+' button
#define minus 16754775 // identifier of the '-' button
#define zero 16738455 // identifier of the '0' button
#define one 16724175 // identifier of the '1' button
#define two 16718055 // identifier of the '2' button
#define three 16743045 // identifier of the '3' button
#define four 16716015 // identifier of the '4' button
#define five 16726215 // identifier of the '5' button



//stepper:

const int stepsPerRevolution = 2048; //how many steps per revolution

Stepper stepper(stepsPerRevolution, 2, 4, 3, 5);
int stepsMadeCounter = 0;          //recording the location of stepper, to stop the stepper from going too far in either direction
int stepsDif = 0;         //var to allow for the integration of the potentiometer with the stepper
int autoFuncWorking = 0; //var to track if the auto func has been asked to be on or off by the user's button clicking
int isModePressed = 0; //var to use instead of digital read button (prior to using ir)
int target = 257; //inital value for target for the stepper to work towards in auto func


//servo:

Servo servo; // Create a new servo object

#define servoPin 6 // Define the servo pin

int servoAngle = 0; // Create a variable to store the servo position:
int speedAdjust = 0; //the variable that allows for the rate of fire being variable
int servoOff = 0; //the variable that manages if the servo has been asked to come off
int servoOn = 0; //the variable that manages if the servo has been asked to come on
int pause = 0; //used to allow for the execution of the servo motor without taking too much time out of other accessories
int letsBeginFunc = 0; //allows for the first stage to occur without trouble the second time around
int goingUp = 1; //allows for the servo func to sense if it needs to increase or decrease in degrees
int goingDown = 0; //allows for the servo func to sense if it needs to increase or decrease in degrees
int weAreDone = 0; //tells when the rotation is done
int waitingTime = 0; //used to allow for servo rate of fire variability

// led

#define led 8 // Define the led pin

int ledOn = 0; //variable that equals 1 when a button is clicked on the ir remote
int ledTimer = 0; //allows for the led to only display a certain timeframe

//=========================================================================================================================================================================================


void setup() {
  
  stepper.setSpeed(1000); //setting the speed of the stepper

  Serial.begin(9600); //starting the serial print for tracking
  
  irrecv.enableIRIn(); // Start the receiver

  servo.attach(servoPin); // Attach the Servo variable to a pin

  pinMode(led, OUTPUT); // Declare the LED as an output

}


//=========================================================================================================================================================================================


void autoFunc() { // the function that allows for automatic rotation
 

  if (stepsMadeCounter > 255) { //tells the stepper to turn around once it reaches its limit (255)
    target = -257; //target value for it to turn around
  }

  if (stepsMadeCounter < -255) { //tells the stepper to turn around once it reaches its limit (255)
    target = 257; //target value for it to turn around
  }

  Serial.print("Target: ");
  Serial.println(target);
  Serial.print("stepsMadeCounter: ");
  Serial.println(stepsMadeCounter);
  
  
  stepsDif = target - stepsMadeCounter; //the difference in steps between the target value and the current value
  

  if (stepsDif > 0) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
    stepper.step(1); //moves stepper
    stepsMadeCounter = stepsMadeCounter + 1; //keeps tracking where the stepper is in steps
  }

  if (stepsDif < 0) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
    stepper.step(-1); //moves stepper
    stepsMadeCounter = stepsMadeCounter - 1; //keeps tracking where the stepper is in steps
  }
  
}


//=========================================================================================================================================================================================


void servoFunc() {
  
  Serial.print("servo Func Started: ");
  Serial.println(" ");

            
   Serial.print("Servo Angle = ");
   Serial.print(servoAngle);
   Serial.println(" ");

   Serial.print("Pause = ");
   Serial.print(pause);
   Serial.println(" ");

   Serial.print("letsBeginFunc = ");
   Serial.print(letsBeginFunc);
   Serial.println(" ");
 

   if ((pause == 1) || (letsBeginFunc == 1)) {//allows for the first stage to occur without trouble the second time around ) { //whenever a button of 1-5 is clicked, this is the loop that the servo conducts, which is put into stages to allow for easy streamline into everything else
        
        Serial.print("waitingTime: ");
        Serial.print(waitingTime);
        Serial.print(" ");
              
      if (waitingTime < speedAdjust) {
        waitingTime = waitingTime + 1;
        Serial.print("Speed Delay ");
         Serial.println(" ");
      }
      else {
      
      pause = 0; //var used to determine when the 'delay' should occur (in this case it is now off)
      letsBeginFunc = 0; //var used to start the inital func, which is now off
      goingUp = 1; //var used to figure out if the servo is increasing or decreasing in degree's (going up now)
      waitingTime = 0;

    Serial.print("Stage 1 done: ");
     Serial.println(" ");
      }
    return;
   }


    if (goingUp == 1) { //var used to figure out if the servo is increasing or decreasing in degree's (going up now)

      if (servoAngle > 0) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle - 1; //keeps tracking where the stepper is in steps                
      }
      
      
     else {
        goingUp = 0; //var used to figure out if the servo is increasing or decreasing in degree's (going down now)
        goingDown = 1; //var used to figure out if the servo is increasing or decreasing in degree's (going down now)
        
        Serial.print("Stage 2 done **********");
        Serial.println(" ");     
      }
      
      Serial.print("Stage 2 doing: ");
     Serial.println(" ");

     return;
    }


    if (goingDown == 1) { //var used to figure out if the servo is increasing or decreasing in degree's (going down now)

     if (servoAngle < 90) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        //servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        //servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps  
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
        servo.write(servoAngle); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps         
      }
      
     else {
        goingDown = 0; //var used to figure out if the servo is increasing or decreasing in degree's (going up now)
        pause = 1; //var used to determine when the 'delay' should occur (in this case it is now off)
        
        Serial.print("Stage 3 done **********");
        Serial.println(" ");     
      }
      

     return;
    }
    
  }
  


//=========================================================================================================================================================================================


void ledFunc() { //func used to alert user that their signal from ir-remote is being recieved

  Serial.print("LED FUNC: ");
  Serial.println(" ");

  if (ledTimer < 10) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
    Serial.print("LED ON: ");
    Serial.println(" ");
    digitalWrite(led, HIGH); // Turn the LED on
  
  ledTimer = ledTimer + 1; //keeps tracking where the stepper is in steps
  }

  else {
    digitalWrite(led, LOW); // Turn the LED off
    Serial.print("LED OFF: ");
    Serial.println(" ");
    ledTimer = 0; //led timer that goes to 10 will reset for next time with button click...
    ledOn = 0; //stop led on so it doesn't continually do it... It will wait till next button click...
  }

  
}


//=========================================================================================================================================================================================


void loop() { 

  if (ledOn == 1) { //ledOn is at 1 when any button is clicked
    
    ledFunc(); //go to led func
    
  }

  if (autoFuncWorking == 1) { //STEPPER: continuous loop if autoFunc has been selected to be on
        autoFunc(); //nothings stopping you from the function not working so it continues... 
  }


  if (servoOn == 1) { //if the servo is meant to be on lets start the servo Function
    
    servoFunc(); //go to servo func
    
  }

  


  if (irrecv.decode(&results)) { //decode the results
    unsigned int value = results.value;
    switch(value) { //find the value that was clicked and execute the relevant code - all of the ("case")'s are in this value search



      
      case mode: //STEPPER: button used to switch between 'auto' and 'manual' mode for the stepper

        ledOn = 1; //led is on to alert user that their input has worked
        
        Serial.print("'mode' pressed ");
        Serial.println();

        isModePressed = 1;

        if (isModePressed == 1) { // if button is pressed and hasn't been before (to avoid long presses)

          if (autoFuncWorking == 0) { //is the auto func working already?
            autoFuncWorking = 1; //the auto func is now working
            
            Serial.print("Auto Func Started: ");
            Serial.print(" ");
            
          }
          else {
            autoFuncWorking = 0; //the auto func is no longer working
          }
        }


      break;
  



      case forwards: //STEPPER: button used for manual mode, where a click contributes to the movement of 130 steps (designed to be quick)

       ledOn = 1; //led is on to alert user that their input has worked

        if (ledOn == 1) { //put here to make led light up before everything else
    
          ledFunc();
    
        }
        
       Serial.print("'->>' pressed ");
       Serial.println();

       if (autoFuncWorking == 0) { //manual func only works when auto is off
          for (int i = 0; i <= 19; i++) {
            if (stepsMadeCounter < 255) { //the 45 degree threshold = 255
              stepper.step(7);
              stepsMadeCounter = stepsMadeCounter + 7; //keeps tracking where the stepper is in steps

              Serial.print("**moving**");
              Serial.println();  

              Serial.print("stepsMadeCounter: ");
              Serial.print(stepsMadeCounter);
              Serial.print(" ");
            }
          }
        } 
      
      break;




      case backwards: //STEPPER: button used for manual mode, where a click contributes to the movement of 130 steps (designed to be quick)

       ledOn = 1; //led is on to alert user that their input has worked

        if (ledOn == 1) { //put here to make led light up before everything else
    
          ledFunc();
    
        }
            
       Serial.print("'<<-' pressed ");
       Serial.println();

        if (autoFuncWorking == 0) { //manual func only works when auto is off
          for (int i = 0; i <= 19; i++) {
            if (stepsMadeCounter > -255) { //the 45 degree threshold = 255
              stepper.step(-7);
              stepsMadeCounter = stepsMadeCounter - 7; //keeps tracking where the stepper is in steps

              Serial.print("**moving**");
              Serial.println();  

              Serial.print("stepsMadeCounter: ");
              Serial.print(stepsMadeCounter);
              Serial.print(" ");
            }
          }
        } 

      break;
      


    
      case plus: //STEPPER: button used for manual mode, where a click contributes to the movement of 10 steps (for fine tuning)
        
        ledOn = 1; //led is on to alert user that their input has worked

        if (ledOn == 1) { //put here to make led light up before everything else
    
          ledFunc();
    
        }
               
        Serial.print("'+' pressed ");
        Serial.println();

        
        if (autoFuncWorking == 0) { //manual func only works when auto is off
         for (int i = 0; i <= 10; i++) {
           if (stepsMadeCounter < 255) { //the 45 degree threshold = 255
              stepper.step(7);
              stepsMadeCounter = stepsMadeCounter + 7; //keeps tracking where the stepper is in steps

              Serial.print("**moving**");
              Serial.println();  

              Serial.print("stepsMadeCounter: ");
              Serial.print(stepsMadeCounter);
              Serial.print(" ");
            }
          }
        } 

      break;



      
      case minus: //STEPPER: button used for manual mode, where a click contributes to the movement of 10 steps (for fine tuning)
        
        ledOn = 1; //led is on to alert user that their input has worked

        if (ledOn == 1) { //put here to make led light up before everything else
    
          ledFunc();
    
        }
        
        Serial.print("'-' pressed ");
        Serial.println();

        if (autoFuncWorking == 0) { //manual func only works when auto is off
         for (int i = 0; i <= 10; i++) {
           if (stepsMadeCounter > -255) { //the 45 degree threshold = 255
              stepper.step(-7);
              stepsMadeCounter = stepsMadeCounter + -7; //keeps tracking where the stepper is in steps

              Serial.print("**moving**");
              Serial.println();  

              Serial.print("stepsMadeCounter: ");
              Serial.print(stepsMadeCounter);
              Serial.print(" ");
            }
          }
        } 

      break;




      case zero: //when the '0' button is clicked the following code is executed

        ledOn = 1; //led is on to alert user that their input has worked
      
        servoOff = 1; //the servo is now off
        servoOn = 0; //meaning that the servo isn't on
        servoAngle = 120;
        Serial.print("'0' pressed ");
        Serial.println();
        
       if (servoAngle > 0 ) { //from the value of the stepsDif, we know if we need to increase or decrease in steps to achieve our target
        servo.write(1); //pickup and dump the ball
        servoAngle = servoAngle + 1; //keeps tracking where the stepper is in steps
      }
        
      break;
    
    
    
    
      case one: //when the '1' button is clicked the following code is executed
        
        ledOn = 1; //led is on to alert user that their input has worked
        
        servoOff = 0; //the servo is on, so it cant be off
        servoOn = 1; // the servo is now on
        servoAngle = 90;
        Serial.print("'1' pressed ");
        Serial.println();
        speedAdjust = 5; //changes the rate of fire (slowest)

        letsBeginFunc = 1;
      break;    
    
    
    
    
      case two: //when the '2' button is clicked the following code is executed
        
        ledOn = 1; //led is on to alert user that their input has worked
        
        servoOff = 0; //the servo is on, so it cant be off
        servoOn = 1; // the servo is now on
        servoAngle = 90;
        Serial.print("'2' pressed ");
        Serial.println();
        speedAdjust = 10; //changes the rate of fire (2nd slowest)
        
      break;    
    
    
    
    
      case three: //when the '3' button is clicked the following code is executed
        
        ledOn = 1; //led is on to alert user that their input has worked
        
        servoOff = 0; //the servo is on, so it cant be off
        servoOn = 1; // the servo is now on
        servoAngle = 90;
        Serial.print("'3' pressed ");
        Serial.println();
        speedAdjust = 7; //changes the rate of fire (middle)
        
      break;    
    
    
    
    
      case four: //when the '4' button is clicked the following code is executed
        
        ledOn = 1; //led is on to alert user that their input has worked
        
        servoOff = 0; //the servo is on, so it cant be off
        servoOn = 1; // the servo is now on
        servoAngle = 90;
        Serial.print("'4' pressed ");
        Serial.println();
        speedAdjust = 4; //changes the rate of fire (2nd fastest)
        
      break;    
    
    
    

      case five: //when the '5' button is clicked the following code is executed
        
        ledOn = 1; //led is on to alert user that their input has worked
        
        servoOff = 0; //the servo is on, so it cant be off
        servoOn = 1; // the servo is now on
        servoAngle = 90;
        Serial.print("'5' pressed ");
        Serial.println();
        speedAdjust = 1; //changes the rate of fire (fastest)
        
      break;    


    }

    irrecv.resume(); // Receive the next value

   }
    
}