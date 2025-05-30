#include <Ps3Controller.h>
#include <ESP32Servo.h>
//lamp and servo
bool led1State = false;
#define LED1_PIN 15
#define LED2_PIN 2
Servo myservo;
int pos = 0;
int servoPin = 13;
//Right motor
int enableRightMotor=22; 
int rightMotorPin1=16;
int rightMotorPin2=17;
//Left motor
int enableLeftMotor=23;
int leftMotorPin1=18;
int leftMotorPin2=19;

const int PWMFreq = 500; /* 1 KHz */
const int PWMResolution = 8;
const int rightMotorPWMSpeedChannel = 4;
const int leftMotorPWMSpeedChannel = 5;

void notify()
{
  int yAxisValue =(Ps3.data.analog.stick.ly);  //Left stick  - y axis - Menggerakan Maju Mundur
  int xAxisValue =(Ps3.data.analog.stick.rx);  //Right stick - x axis - Menggerakan kanan kiri

  int throttle = map( yAxisValue, 127, -127, -255, 255);//Nilai Kecepatan Maju Mundur
  int steering = map( xAxisValue, -127, 127, -255, 255);  //Nilai Kecepatan Kanan Kiri
  int motorDirection = 1;
  //lampu
  bool div= false;
  
  if (throttle < 0)       //Membalikan rotasi mesin
  {
    motorDirection = -1;    
  }

  int rightMotorSpeed, leftMotorSpeed;// Menggabungkan data agar dapat menerima 2 data analog
  rightMotorSpeed =  abs(throttle) - steering;
  leftMotorSpeed =  abs(throttle) + steering;
  rightMotorSpeed = constrain(rightMotorSpeed, -255, 255);
  leftMotorSpeed = constrain(leftMotorSpeed, -255, 255);

  //Serial.println(rightMotorSpeed);
  //Serial.println(leftMotorSpeed);  
  rotateMotor(rightMotorSpeed * motorDirection, leftMotorSpeed * motorDirection);//function dari Tombol dan Analog Motor

if (Ps3.event.button_down.cross ) {//Menyalakan Lampu
    Serial.println("Cross pressed");
    led1State = !led1State ;
    
    digitalWrite(LED1_PIN, led1State);
    digitalWrite(LED2_PIN, led1State);
  }
  if (Ps3.event.button_up.cross) {//Mematikan Lampu
    Serial.println("Cross released");
    digitalWrite(LED2_PIN, led1State);
    digitalWrite(LED1_PIN, led1State);
}
  if (Ps3.event.button_down.r2) { //Membuka dan menutup katub
    Serial.println("R2 pressed");
    myservo.write(90);//Servo Terbuka
  }
  if (Ps3.event.button_up.r2) {
    Serial.println("R2 released");
    myservo.write(0);//Servo tertutup
    
}
}
void onConnect()
{
  Serial.println("Connected!.");//terkoneksi
}

void onDisConnect()
{
  rotateMotor(0, 0);
  Serial.println("Disconnected!.");    //terputus
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)//arah motor
{
  if (rightMotorSpeed < 10)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 10)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }
  
  if (leftMotorSpeed < 10)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 10)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  } 
  ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
  ledcWrite(leftMotorPWMSpeedChannel, abs(leftMotorSpeed));   
}

void setUpPinModes()
{
  pinMode(enableRightMotor,OUTPUT);//deklarasi pin
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);
  
  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);

  //Setting PWM for motor speed
  ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);//menggabungkan data kecepatan dengan motor
  ledcSetup(leftMotorPWMSpeedChannel, PWMFreq, PWMResolution);  
  ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
  ledcAttachPin(enableLeftMotor, leftMotorPWMSpeedChannel);  //memasukan data motor sebagai sinyal PWM
  
  rotateMotor(0, 0);
}


void setup()
{
  setUpPinModes();
  Serial.begin(115200);//kecepatan pembacaan data cpu
  Ps3.attach(notify);//function mencari data
  Ps3.attachOnConnect(onConnect);//terkoneksi
  Ps3.attachOnDisconnect(onDisConnect);//terputus
  Ps3.begin("00:00:00:00:00:00");//MAC Address bluetooth Joystick
  Serial.println("Ready.");//Siap

  //lampu
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  //servo
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 1000, 2000);
}

void loop()
{
}