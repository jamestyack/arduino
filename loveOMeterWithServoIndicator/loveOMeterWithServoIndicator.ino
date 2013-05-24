#include <Servo.h>

Servo myServo;
const int SENSOR_PIN = A0;

const float baselineTemp = 18.00;
float temp = baselineTemp;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  myServo.write(0);
  delay(100);
  myServo.write(45);
  delay(100);
  myServo.write(0);
  delay(100);
}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  // convert voltage to temp in degrees c
  float newTemp = (voltage - .5) * 100;
  Serial.print(", degress C newTemp: ");
  Serial.println(newTemp);
  float tempDiff = newTemp - temp;
  Serial.print(", Tempdiff: ");
  Serial.print(tempDiff);
  tempDiff = (tempDiff<0) ? tempDiff * -1.0 : tempDiff;
  Serial.print(", Tempdiff after convert: ");
  Serial.print(tempDiff);
  if (tempDiff < 1) {
    temp = newTemp;
  }
  Serial.print(", degress C: ");
  Serial.println(temp);
  
  if (temp < baselineTemp+2) {
    Serial.println("0 room");
    myServo.write(1);
  } else if(temp >= baselineTemp+2 && temp < baselineTemp+3.5) {
    Serial.println("45 cool");
    myServo.write(45);
  } else if(temp >= baselineTemp+3.5 && temp < baselineTemp+5) {
    Serial.println("90 warrm");
    myServo.write(80);
  } else if(temp >= baselineTemp+6.5 && temp < baselineTemp+8) {
    Serial.println("135 hot");
    myServo.write(135);
  } else if(temp >= baselineTemp+9.5) {
    Serial.println("180 on fire!");
    myServo.write(170);
  }
  
  delay(500);
}
