#include <Arduino.h>
#include "IRremote.h"
#include "Keyboard.h"

#define pinIR 4
IRrecv irrecv(pinIR);
decode_results results;
int last_btn = 0;

void setup() {

 irrecv.enableIRIn();

}

void loop(){
  if (irrecv.decode()){
        //Serial.println(irrecv.decodedIRData.command, HEX);
        
        
        if((irrecv.decodedIRData.command == 0xC) and last_btn){
            last_btn = 0;
            //Serial.println("btn 1");
            /*Keyboard.begin();
            delay(1000);
            Keyboard.print(KEY_RIGHT_CTRL);
            delay(500);
            Keyboard.print(KEY_RIGHT_CTRL);
            delay(500);
            Keyboard.print(KEY_KP_1);
            delay(500);
            Keyboard.print(KEY_KP_ENTER);
            delay(500);
            Keyboard.end();
            */
        } else if ((irrecv.decodedIRData.command == 0x18) and !last_btn){
            last_btn = 1;
            //Serial.println("btn 2");
            /*
            Keyboard.begin();
            delay(1000);
            Keyboard.print(KEY_RIGHT_CTRL);
            delay(500);
            Keyboard.print(KEY_RIGHT_CTRL);
            delay(500);
            Keyboard.print(KEY_KP_2);
            delay(500);
            Keyboard.print(KEY_KP_ENTER);
            delay(500);
            Keyboard.end();
            */
        }
        
        irrecv.resume();
  }
}
/*
1   FF30CF
2   FF18E7
*/