const int SENSOR_PIN = A0;
const float baselineTemp = 19.00;

void setup() {
  Serial.begin(9600); // open a serial port
  for (int pinNumber = 2; pinNumber < 7; pinNumber++ ) {
   pinMode(pinNumber, OUTPUT);
   digitalWrite(pinNumber, LOW);
  }
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
  float temp = (voltage - .5) * 100;
  Serial.print(", degress C: ");
  Serial.println(temp);
  
  if (temp < baselineTemp+2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
  } else if(temp >= baselineTemp+2 && temp < baselineTemp+3.5) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if(temp >= baselineTemp+3.5 && temp < baselineTemp+5) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if(temp >= baselineTemp+6.5 && temp < baselineTemp+8) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  } else if(temp >= baselineTemp+9.5) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(50);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(50);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
  delay(50);
  
}
