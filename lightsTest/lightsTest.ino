



void setup() {
  for (int pin=2; pin<8; pin++) {
    pinMode (pin, OUTPUT);
  }
}

void loop() {
  
  for (int pin=2; pin<8; pin++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(5);
  }
  for (int pin=5; pin>2; pin--) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(5);
  }
  delay(5);
}
