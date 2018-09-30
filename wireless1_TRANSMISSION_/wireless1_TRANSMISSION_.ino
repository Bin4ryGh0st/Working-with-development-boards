#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
RF24 radio(7,8);
const byte address[6]="B3299";
void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{
/*
  const char text[]="Transmitting..."; 
  radio.write(&text,sizeof(text));
  delay(1000);
*/
  char text[100]="";
  *text=Serial.read();
  radio.write(&text,sizeof(text));  
}
