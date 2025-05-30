int pwmleft = 5;   //speed left
int pwmright = 6;  //speed right
int fwdleft = 7;
int revleft = 8;
int fwdright = 10;
int revright = 11;


//control lvalue
int valleft = 0;   //joystick (-255.225)
int valright = 0;  //joystick (-255.225)

void kananmaju() {
  digitalWrite(fwdright, 1);
  digitalWrite(revright, 0);
}
void kananmundur() {
  digitalWrite(fwdright, 0);
  digitalWrite(revright, 1);
}
void kirimaju() {
  digitalWrite(fwdleft, 1);
  digitalWrite(revleft, 0);
}
void kirimundur() {
  digitalWrite(fwdleft, 0);
  digitalWrite(revleft, 1);
}

void setup() {
  pinMode(pwmleft, OUTPUT);
  pinMode(pwmright, OUTPUT);
  pinMode(fwdleft, OUTPUT);
  pinMode(revleft, OUTPUT);
  pinMode(fwdright, OUTPUT);
  pinMode(revright, OUTPUT);

  // put your setup code here, to run once:
}

void loop() {
  analogWrite(pwmleft, valleft);
  analogWrite(pwmright, valright);
  if (valleft < 0) {
    kirimundur();
  }
  if (valright < 0) {
    kananmundur();
  }
  if (valleft > 0) {
    kirimaju();
  }
  if (valright > 0) {
    kananmaju();
  }







  // put your main code here, to run repeatedly:
}
