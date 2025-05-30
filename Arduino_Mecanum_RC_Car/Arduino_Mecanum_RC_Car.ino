
//Made by Vantasy

//include the library code:
#include<IBusBM.h>   
#include<AFMotor.h>
IBusBM IBus;     //create IBus object:
//variables to store channel value:
int rcCH1 = 0;
int rcCH2 = 0;
int rcCH3 = 0;
int rcCH4 = 0;
int rcCH5 = 0;
bool rcCH6 = 0;
//create motor objects
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR34_1KHZ);
AF_DCMotor motor4 (4, MOTOR34_1KHZ);
int motorSpeed = 0; //variable to store motor speed:
void setup() {

    IBus.begin(Serial); // iBUS connected to Serial0:

}

void loop() {
  //get the latest value from all channels and map them to one byte:
 rcCH1 = map(IBus.readChannel(0), 1000, 2000, 0, 255);
 rcCH2 = map(IBus.readChannel(1), 1000, 2000, 0, 255);
 rcCH3 = map(IBus.readChannel(2), 1000, 2000, 0, 255);
 rcCH4 = map(IBus.readChannel(3), 1000, 2000, 0, 255);
 rcCH5 = map(IBus.readChannel(4), 1000, 2000, 0, 255);
 rcCH6 = IBus.readChannel(5), 

  motorSpeed = rcCH5;   //store the rcCH5(Channel 5) data in motorSpeed variable:

  


 if(rcCH1 > 150) {          //Check whether the channel1 value is greater than 150. If the condition is true then execute the below code:                         
   MoveRight();  
  }else if (rcCH1 < 100) {  //Check whether the channel1 value is less than 100. If the condition is true then execute the below Code:
   MoveLeft(); 
  }else if (rcCH2 > 150) {  //Check whether the channel2 value is greater than 150. If the condition is true then execute the below Code:
   MoveForward();  
  }else if (rcCH2 < 100) {  //Check whether the channel1 value is less than 100. If the condition is true then execute the below Code:
   MoveBackward();
  }else{                    //If the above conditions are false then execute the below Code:
   Stop();
  }

 if(rcCH6 == 1) {           //Check whether the channel6 value is 1. If the condition is true then execute the below code:
   //Corner Drive Mode:
   if ((rcCH3 > 150)&&(rcCH4 > 100)){
     MoveTopRight();
    }else if ((rcCH3 > 150)&&(rcCH4 < 100)){
     MoveTopLeft();
    }else if ((rcCH3 < 100)&&(rcCH4 > 150)){
     MoveBackRight();
    }else if ((rcCH3 < 100)&&(rcCH4 < 100)) {
     MoveBackLeft();
    }
  }else{                    //If the above condition is false then execute the below Code:
     //Spin Mode:
    if ((rcCH3 > 150)&&(rcCH4 > 100)){
     LeftTurn(); 
    }else if ((rcCH3 > 150)&&(rcCH4 < 100)){
     RightTurn();
    }
  }
}

void MoveForward() { //Move Forward:
 motor1.run(FORWARD);                      //Drive motor1 clockwise:
 motor1.setSpeed(motorSpeed);              //Define motor1 speed:
 motor2.run(FORWARD);                      //Drive motor2 clockwise:
 motor2.setSpeed(motorSpeed);              //Define motor2 speed:
 motor3.run(FORWARD);                      //Drive motor3 clockwise:
 motor3.setSpeed(motorSpeed);              //Define motor3 speed:
 motor4.run(FORWARD);                      //Drive motor4 clockwise:
 motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}

void Stop() { //Stop:
 motor1.run(RELEASE);                       //Stop motor1:
 motor1.setSpeed(0);                        //Define motor1 speed:
 motor2.run(RELEASE);                       //Stop motor2:
 motor2.setSpeed(0);                        //Define motor2 speed:
 motor3.run(RELEASE);                       //Stop motor3:
 motor3.setSpeed(0);                        //Define motor3 speed:
 motor4.run(RELEASE);                       //Stop motor4:
 motor4.setSpeed(0);                        //Define motor4:
}
void MoveBackward () { //Move Backward:
 motor1.run(BACKWARD);                      //Drive motor1 anti-clockwise:
 motor1.setSpeed(motorSpeed);               //Define motor1 speed:
 motor2.run(BACKWARD);                      //Drive motor2 anti-clockwise:
 motor2.setSpeed(motorSpeed);               //Define motor2 speed:
 motor3.run(BACKWARD);                      //Drive motor3 anti-clockwise:
 motor3.setSpeed(motorSpeed);               //Define motor3 speed:
 motor4.run(BACKWARD);                      //Drive motor4 anti-clockwise:
 motor4.setSpeed(motorSpeed);               //Define motor4 speed:
}
void MoveRight() { //Move Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define moto1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveLeft() { //Move Left:
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveTopRight() { //Move Top Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed"
  motor2.run(RELEASE);                      //Stop motor2:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(RELEASE);                      //Stop motor4:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveTopLeft() { //MOve Top Left:
  motor1.run(RELEASE);                      //Stop motor1:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(RELEASE);                      //Stop motor3:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveBackRight() { //Move Back Right:
  motor1.run(RELEASE);                      //Stop motor1:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(RELEASE);                      //Stop motor3:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveBackLeft() { //Move Back Left: 
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(RELEASE);                      //Stop motor2:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(RELEASE);                      //Stop motor4:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void RightTurn() { //Turn Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed :
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void LeftTurn() { //Turn Left:
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
