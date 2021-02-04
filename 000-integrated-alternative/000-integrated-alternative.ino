int dataPin = 2; 
int latchPin = 3;
int clockPin = 4;
int readPin = A0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(readPin);
  Serial.println(value);
  value = map(value, 0, 1023, 0, 8);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, (256 - pow(2, (7-value))));
  Serial.println(value);
  digitalWrite(latchPin, HIGH);
  delay(500);
}
