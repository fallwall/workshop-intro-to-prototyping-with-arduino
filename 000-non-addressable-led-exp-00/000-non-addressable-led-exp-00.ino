// pins to use to control the MOSFETs
#define RED_LED 6
#define GREEN_LED 9
#define BLUE_LED 5

// overall brightness
int brightness = 255;
// each color's brightness
int rBright = 0;
int gBright = 0;
int bBright = 0;
// how fast the fading will happen
int fadeSpeed = 10;

void setup() {
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
   TurnOn();
   delay(5000);
   TurnOff();
}

void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, rBright);
       rBright +=1;
       delay(fadeSpeed);
   }
 
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, gBright);
       gBright +=1;
       delay(fadeSpeed);
   } 
}

void TurnOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, brightness);
       analogWrite(RED_LED, brightness);
       analogWrite(BLUE_LED, brightness);
 
       brightness -= 1;
       delay(fadeSpeed);
   }
}

void loop() {
  
}
