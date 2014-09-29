#include "LPD8806.h"
#include "SPI.h"
int nLEDs = 182;


long anVolt, inches, cm;
int sum=0;
LPD8806 strip = LPD8806(nLEDs);

void setup() {
  // Start up the LED strip
  strip.begin();
  //constant color for performance written only once
  colorStay(strip.Color(0,0,100),10);
  Serial.begin(9600);
 
}

void loop() {
  
  //right
  Serial.print(rangeFind(20, 0));
  Serial.print(" RIGHT");
  Serial.println();
  if (rangeFind(20, 0)<= 130){
    colorWalk(strip.Color(127, 127, 127),1);
  }
 
 //left
 Serial.print(rangeFind(20, 1));
 Serial.print(" LEFT");
 Serial.println();
 if(rangeFind(20,1)<=128){
   revColorWalk(strip.Color(127,127,127),1);
 }


}

void colorStay(uint32_t c, uint8_t wait) {
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
    
  for(uint16_t i=0; i<strip.numPixels()+1; i++) {
  
 
   
    strip.setPixelColor(i, strip.Color(255,100,255));
    strip.setPixelColor(i+1,strip.Color(255,100,255));
    strip.setPixelColor(i+2, strip.Color(255,100,255));
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
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      
      strip.setPixelColor(i, 255);
   

    }
    delay(wait);
  }
}


void  revColorWalk(uint32_t c, uint8_t wait){
  for(uint16_t i=strip.numPixels(); i>0; i--) {
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
        for(uint16_t i=strip.numPixels(); i>0; i--) {
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
          strip.setPixelColor(i-1, 255);
//          strip.setPixelColor(i, 255);
//        strip.show();
       }
     delay(wait); //sets delay of travel
  }
  
}

