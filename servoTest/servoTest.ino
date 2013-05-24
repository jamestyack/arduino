#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
 myServo.attach(9);
 Serial.begin(9600); 
}

void loop() {
  myServo.write(0);
  delay(500);
  myServo.write(45);
  delay(500);
  myServo.write(90);
  delay(500);
  myServo.write(135);
  delay(500);
  myServo.write(180);
  delay(500);
  myServo.write(135);
  delay(500);
  myServo.write(90);
  delay(500);
  myServo.write(45);
  delay(500);
}
