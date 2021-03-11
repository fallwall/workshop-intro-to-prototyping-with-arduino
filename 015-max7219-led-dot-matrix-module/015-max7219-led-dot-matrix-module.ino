#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime1=500;
unsigned long delaytime2=50;
unsigned long  delaytime = 500;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime1);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime2);
    lc.setRow(0,row,B10100000);
    delay(delaytime2);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime2);
      lc.setRow(0,row,B10100000);
      delay(delaytime2);
      lc.setRow(0,row,(byte)0);
    }
  }
}

void writeOnMatrixAll() {
  /* here is the data for the characters */
  byte A[5]={ B01111111,B10001000,B10001000,B10001000,B01111111  };
  byte B[5]={ B11111111,B01001001,B01001001,B00110110,B00000000  };
  byte C[5]={ B01111110,B10000001,B10000001,B10000001,B01000010  };
  byte D[5]={ B01111111,B01000001,B01000001,B00111110,B00000000  };
  byte E[5]={ B11111110,B10010010,B10010010,B10010010,B00000000  };
  byte F[5]={ B01111111,B01001000,B01001000,B01001000,B00000000  };
  byte G[5]={ B01111110,B10000001,B10001001,B10001001,B01001110  };
  byte H[5]={ B01111111,B00001000,B00001000,B00001000,B01111111  };
  byte I[5]={ B00100001,B00100001,B00111111,B00100001,B00100001  };
  byte J[5]={ B00000110,B00000001,B00000001,B00000001,B11111110  };
  byte K[5]={ B11111111,B00011000,B00100100,B01000010,B10000001  };
  byte L[5]={ B11111111,B00000001,B00000001,B00000001,B00000001  };
  byte M[5]={ B11111100,B01000000,B00100000,B01000000,B11111100  };
  byte N[5]={ B00111111,B00010000,B00001000,B00000010,B00111111  };
  byte O[5]={ B01111110,B10000001,B10000001,B10000001,B01111110  };
  byte P[5]={ B11111111,B10001000,B10001000,B10001000,B01110000  };
  byte Q[5]={ B01111100,B10000010,B10000010,B10000011,B01111101  };
  byte R[5]={ B11111111,B10001000,B10001100,B10001010,B01110001  };
  byte S[5]={ B00110001,B01001001,B01001001,B01001001,B01000110  };
  byte T[5]={ B00100000,B00100000,B00111111,B00100000,B00100000  };
  byte U[5]={ B00111110,B00000001,B00000001,B00000001,B00111110  };
  byte V[5]={ B00111100,B00000010,B00000001,B00000010,B00111100  };
  byte W[5]={ B00111111,B00000010,B00000100,B00000010,B00111111  };
  byte X[5]={ B00010001,B00001010,B00000100,B00001010,B00010001  };
  byte Y[5]={ B11100000,B00010000,B00001111,B00010000,B11100000  };
  byte Z[5]={ B00010001,B00010011,B00010101,B00011001,B00010001  };
  byte r[5]={ B00111110,B00010000,B00100000,B00100000,B00010000  };

  /* now display them one by one with a small delay */
  lc.setRow(0,0,R[0]);
  lc.setRow(0,1,R[1]);
  lc.setRow(0,2,R[2]);
  lc.setRow(0,3,R[3]);
  lc.setRow(0,4,R[4]);
  delay(delaytime);
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  delay(delaytime);
  lc.setRow(0,0,E[0]);
  lc.setRow(0,1,E[1]);
  lc.setRow(0,2,E[2]);
  lc.setRow(0,3,E[3]);
  lc.setRow(0,4,E[4]);
  delay(delaytime);
  lc.setRow(0,0,C[0]);
  lc.setRow(0,1,C[1]);
  lc.setRow(0,2,C[2]);
  lc.setRow(0,3,C[3]);
  lc.setRow(0,4,C[4]);
  delay(delaytime);
  lc.setRow(0,0,A[0]);
  lc.setRow(0,1,A[1]);
  lc.setRow(0,2,A[2]);
  lc.setRow(0,3,A[3]);
  lc.setRow(0,4,A[4]);
  delay(delaytime);
  lc.setRow(0,0,T[0]);
  lc.setRow(0,1,T[1]);
  lc.setRow(0,2,T[2]);
  lc.setRow(0,3,T[3]);
  lc.setRow(0,4,T[4]);
  delay(delaytime);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime);
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime2);
    lc.setColumn(0,col,B10100000);
    delay(delaytime2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime2);
      lc.setColumn(0,col,B10100000);
      delay(delaytime2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime2);
      lc.setLed(0,row,col,true);
      delay(delaytime2);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime2);
        lc.setLed(0,row,col,true);
        delay(delaytime2);
      }
    }
  }
}

void loop() { 
  writeOnMatrixAll();
//writeArduinoOnMatrix();
//  rows();
//  columns();
//  single();
}
