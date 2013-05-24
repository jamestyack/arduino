
int notes[] = {262, 294, 330, 349};

void setup() { 
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  if (keyVal>0) {
    Serial.println(keyVal);
  }
  
  if(keyVal > 1015) {
    tone (9, notes[0]);
  }
  else if (keyVal >= 990 && keyVal <= 1010) {
    tone (9, notes[1]);
  }
  else if (keyVal >= 505 && keyVal <= 515) {
    tone (9, notes[2]);
  }
  else if (keyVal >= 1 && keyVal <= 20) {
    tone (9, notes[3]);
  }
  else {
    noTone(9);
  }
}
