#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
  
RF24 radio(7, 8); // CE, CSN
  
const byte address[6] = "01101";

void ReceiverSetup(){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void ReceiverLoop(){  
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    String test = text;
    int newDirection = test.toInt();
    ChangeDirection(newDirection, 255);
    Serial.println(newDirection);
  }
}
