int dataPin = 2; 
// SER (data)
int latchPin = 3;
// SRCLK (latch)
int clockPin = 4;
// RCLK (clock)
int readPin = A0;

int marchingAnts[2] = {85,170};
int marchingAnts2[3] = {36, 73, 146};
int pingPong[15]={128,64,32,16,8,4,2,1,2,4,8,16,32,64,128};
int meetInMiddle[7] = {129,66,36,24,36,66,129};
int dialControl[8]={128,192,224,240,248,252,254,255};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

//void sequence(int num) {
//  digitalWrite(latchPin, LOW);
//  shiftOut(dataPin, clockPin, MSBFIRST, num);
//  delay(1000);
//  digitalWrite(latchPin, HIGH);
//}

void loop() {
  int value = analogRead(readPin);
  value = map(value, 0, 1023, 0, 8);
  
// single scroll: int i = 1; i < 256; i *= 2
//  for (int i = 0; i < 15; i ++) {
   digitalWrite(latchPin, LOW);
   // shiftOut(dataPin, clockPin, bitOrder, value)
   // bitOrder: MSBFIRST or LSBFIRST
   // value: the data to shift out. 
   // Allowed data types: byte.
   shiftOut(dataPin, clockPin, MSBFIRST, dialControl[value]);
   // decimal -> binary - 8 byte string.
   digitalWrite(latchPin, HIGH);
   delay(500);
//   }
  // Marching Ants 1:
//  sequence(85);
//  sequence(170);
  // Marching Ants 2:
//  sequence(292);
//  sequence(170);
//  sequence(85);
}
