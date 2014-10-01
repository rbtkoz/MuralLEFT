#include <avr/pgmspace.h>
#include "LPD8806.h"
#include "SPI.h"
int nLEDs = 182;




long anVolt, inches, cm;
int sum=0;
LPD8806 strip = LPD8806(nLEDs);

//neopixel gamma correction
//const uint8_t PROGMEM gamma[] = {
//    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
//    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
//    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
//    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
//   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
//   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
//   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
//   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
//   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
//   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
//   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
//  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
//  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
//  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
//  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
//  
 //Gamma correction for LED brightness 
const uint8_t PROGMEM gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3,
    3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  5,  5,
    5,  5,  5,  5,  6,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,
    8,  8,  9,  9,  9,  9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12,
   13, 13, 13, 14, 14, 14, 15, 15, 15, 16, 16, 16, 17, 17, 18, 18,
   18, 19, 19, 20, 20, 21, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25,
   26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 32, 32, 33, 33, 34,
   34, 35, 36, 36, 37, 38, 38, 39, 39, 40, 41, 41, 42, 43, 44, 44,
   45, 46, 46, 47, 48, 49, 49, 50, 51, 52, 52, 53, 54, 55, 56, 57,
   57, 58, 59, 60, 61, 62, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71,
   72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
   88, 89, 91, 92, 93, 94, 95, 96, 97, 99,100,101,102,103,105,106,
  107,108,110,111,112,114,115,116,117,119,120,122,123,124,126,127 };


uint32_t magenta = strip.Color(127, 0, 127);
uint32_t blue = strip.Color(0, 0, 127);
uint32_t white = strip.Color(127, 127, 127);

void setup() {
  // Start up the LED strip
  strip.begin();
  //constant color for performance written only once
  colorStay(strip.Color(pgm_read_byte(&gamma(0), pgm_read_byte(&gamma[0]), pgm_read_byte(&gamma[127])),1);
  Serial.begin(9600);

}

void loop() {

  //right
  Serial.print(rangeFind(20, 0));
  Serial.print(" RIGHT");
  Serial.println();

  if (rangeFind(20, 0)<= 130){
    colorWalk(pgm_read_byte(&gamma(127), pgm_read_byte(&gamma[127]), pgm_read_byte(&gamma[127])),1);

  }

  //left
  Serial.print(rangeFind(20, 1));
  Serial.print(" LEFT");
  Serial.println();
  if(rangeFind(20,1)<=128){
    revColorWalk(pgm_read_byte(&gamma(127), pgm_read_byte(&gamma[127]), pgm_read_byte(&gamma[127])),1);
  }


}

void colorStay(uint32_t c, uint16_t wait) {
  int i;
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
  }
}



int rangeFind(int avgrange, int anPin){
  //range finder value conversion math
  for(int i = 0; i < avgrange ; i++){
    //Used to read in the analog voltage output that is being sent by the MaxSonar device.
    //Scale factor is (Vcc/512) per inch. A 5V supply yields ~9.8mV/in
    //Arduino analog pin goes from 0 to 1024, so the value has to be divided by 2 to get the actual inches
    anVolt = analogRead(anPin)/2;
    sum += anVolt;
    delay(10);
  } 
  inches = sum/avgrange;
  cm = inches * 2.54;
  sum = 0;
  return cm;
}


// Fill the dots progressively along the strip.
void colorWalk(uint32_t c, uint8_t wait) {

  int i;

  for(uint32_t i=0; i<strip.numPixels()+1; i++) {



    strip.setPixelColor(i, c);
    strip.setPixelColor(i+1,c);
    strip.setPixelColor(i+2, c);
    strip.setPixelColor(i+3, c);
    strip.setPixelColor(i+4, c);
    strip.setPixelColor(i+5, c);
    //    strip.setPixelColor(i+6, c);
    //    strip.setPixelColor(i+7, c);
    //    strip.setPixelColor(i+8, c);
    //    strip.setPixelColor(i+9, c);
    //    strip.setPixelColor(i+10, c);
    //     strip.setPixelColor(i+11, c);
    //    strip.setPixelColor(i+12, c);
    //    strip.setPixelColor(i+13, c);
    //    strip.setPixelColor(i+14, c);
    //    strip.setPixelColor(i+15, c);
    //    strip.setPixelColor(i+16, c);
    //    strip.setPixelColor(i+17, c);
    //    strip.setPixelColor(i+18, c);
    //    strip.setPixelColor(i+19, c);
    //    strip.setPixelColor(i+20, c);
    //    strip.setPixelColor(i+21, c);
    //    strip.setPixelColor(i+22, c);
    //    strip.setPixelColor(i+23, c);
    //     strip.setPixelColor(i+24,c);
    //    strip.setPixelColor(i+25, c);
    //    strip.setPixelColor(i+26, c);
    //      strip.setPixelColor(i+27, c);
    //    strip.setPixelColor(i+28, c);
    //    strip.setPixelColor(i+29, c);
    //    strip.setPixelColor(i+30, c);
    //    strip.setPixelColor(i+31, c);
    //    strip.setPixelColor(i+32, c);
    //    strip.setPixelColor(i+33, c);
    //    strip.setPixelColor(i+34, c);
    //    strip.setPixelColor(i+35, c);
    //    strip.setPixelColor(i+36, c);
    //    strip.setPixelColor(i+37, c);
    //    strip.setPixelColor(i+38, c);
    //     strip.setPixelColor(i+39,c);
    //    strip.setPixelColor(i+40, c);
    //    strip.setPixelColor(i+42, c);

    strip.show();

    //      strip.setPixelColor(i, 0);
    for(uint32_t i=0; i<strip.numPixels(); i++) {



      strip.setPixelColor(i, pgm_read_byte(&gamma(0), pgm_read_byte(&gamma[0]), pgm_read_byte(&gamma[127]));

    }
    delay(wait);
  }
}


void  revColorWalk(uint32_t c, uint8_t wait){
  for(uint32_t i=strip.numPixels(); i>0; i--) {
    //      strip.setPixelColor(i-13, c);
    //      strip.setPixelColor(i-12, c);
    //      strip.setPixelColor(i-11, c);
    //      strip.setPixelColor(i-10, c);
    //      strip.setPixelColor(i-9, c);
    //      strip.setPixelColor(i-8, c);
    strip.setPixelColor(i-7, c);
    strip.setPixelColor(i-6, c);
    strip.setPixelColor(i-5, c);
    strip.setPixelColor(i-4, c);
    strip.setPixelColor(i-3, c);
    strip.setPixelColor(i-2, c);
    //      strip.setPixelColor(i-1, c);
    //      strip.setPixelColor(i, c);
    //      

    strip.show();
    for(uint32_t i=strip.numPixels(); i>0; i--) {
      //          strip.setPixelColor(i-13, 255);
      //          strip.setPixelColor(i-12, 255);
      //          strip.setPixelColor(i-11, 255);
      //          strip.setPixelColor(i-10, 255);
      //          strip.setPixelColor(i-9, 255);
      //          strip.setPixelColor(i-8, 255);
      //          strip.setPixelColor(i-7, 255);
      //          strip.setPixelColor(i-6, 255);
      //          strip.setPixelColor(i-5, 255);
      //          strip.setPixelColor(i-4, 255);
      //          strip.setPixelColor(i-3, 255);
      //          strip.setPixelColor(i-2, 255);
      strip.setPixelColor(i-1, pgm_read_byte(&gamma(0), pgm_read_byte(&gamma[0]), pgm_read_byte(&gamma[127]));
      //          strip.setPixelColor(i, 255);
      //        strip.show();
    }
    delay(wait); //sets delay of travel
  }

}


