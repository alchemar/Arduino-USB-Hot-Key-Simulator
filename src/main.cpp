#include <Arduino.h>
#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>
//#include <String.h>

RH_ASK rf_driver(2000,5,4);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("starting");
  if(!rf_driver.init()){
    Serial.println("rf failed");
  } else {
    Serial.println("rf initialized");
  }
}


void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = 2;
    //Serial.println("loop");
 
    if (rf_driver.recv(buf, &buflen)) // Non-blocking
    {
        String recv = "";
        for(int i=0;i<buflen;i++){
          recv += String(buf[i]);
        }
        // Message with a good checksum received, dump it.
        //rf_driver.printBuffer("Got:", buf, buflen);
        Serial.println(recv);
        Serial.print("recv");
    }
}
