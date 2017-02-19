#include <SPI.h>
#include <Ethernet.h>

EthernetClient client;

byte mac[6] = {0x00,0x00,0x00,0x00,0x00,0x00};
byte oct = 5;

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{  
  if(mac[oct] >= 255)
  oct--;
  
  mac[oct] += 0x01;
  Ethernet.begin(mac);
  Serial.print("IP Gastada: ");
  for (int oct = 0;oct < 4;oct++) 
  {
    Serial.print(Ethernet.localIP()[oct],DEC);
    Serial.print(".");
  }
  Serial.print("  with MAC = ");
  for (oct = 0;oct < 6;oct++) 
  {
    Serial.print(mac[oct],HEX);
    Serial.print(":");
  }
  Serial.println();
}
