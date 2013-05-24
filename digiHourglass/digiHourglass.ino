const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;
boolean buzzer = false;

int led = 2;

long interval = 6000;

void setup() {
  Serial.begin(9600);
  for (int x=2; x<8; x++) {
    pinMode (x, OUTPUT);
  }
  pinMode(switchPin,INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > interval) {
    if (led == 7) {
      buzzer = true;
    }
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led = led < 7 ? led+1 : led;
    Serial.println(led);
  }
  
  if (buzzer == true) {
    tone (9, 349);
  }
  
  switchState = digitalRead(switchPin);
  
  
  if (switchState != prevSwitchState) {
    for (int x=2; x<8; x++) {
      digitalWrite(x, LOW);
    }
    led=2;
    buzzer = false;
    previousTime=currentTime;
  }
  prevSwitchState = switchState;
}

