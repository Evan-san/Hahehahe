#include <Adafruit_PWMServoDriver.h>
#include <leg.h>
#include <move.h>


#define SERVOMIN  125                                                 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625                                                 // this is the 'maximum' pulse length count (out of 4096)



void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60);
  board2.begin();
  board2.setPWMFreq(60);                  // Analog servos run at ~60 Hz updates
 for (int i = 0; i <= 18; i++) {
    setServoAngle(i, defaultangle[i]);
    delay(500);
    
  }
  delay(1000);
      delay(1000);
      leg1(90,30,0);delay(1000);leg2(90,30,0);delay(1000);leg3(90,30,0);delay(1000);leg4(90,30,0);delay(1000);leg5(90,30,0);delay(1000);leg6(90,30,0);
      delay(3000);
      leg1(90,90,0);leg2(90,90,0);leg3(90,90,0);leg4(90,90,0);leg5(90,90,0);leg6(90,90,0);
      delay(1000);
      }

void loop() 
 {
 
      
      

  }

