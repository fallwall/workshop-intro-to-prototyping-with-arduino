int lights[6]= {3, 5, 6, 9, 10, 11};
int readPin = A0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(lights[i], OUTPUT);
   }
}

void lightup(int num) {
  for (int i = 0; i < 6; i++) {
     digitalWrite(lights[i], LOW);
   }
  for (int i = 0; i < num; i++) {
    digitalWrite(lights[i], HIGH);
  }
  
}

void loop() {
  int value = analogRead(readPin);
//  Serial.println(value);
  value = map(value, 0, 1023, 0, 7);
  Serial.println(value);
  lightup(value);
  delay(500);
}
