#include <MKRWAN_v2.h>

LoRaModem modem;

String appEui="0000000000000003";                                             
String appKey="F5AC0A7FF4331CF5D0E8C79E67566A18"; 


void TTNsetup() {
   
   OLEDlms(" TTN setup "); 
   
  modem.begin(EU868);
  
  int connected = modem.joinOTAA(appEui, appKey);
   if(connected){
   OLEDlms(" TTN OK ");  
    delay(1000);  
   }
    else
    OLEDlms(" TTN Failed ");  
}

void sendtoTTN(){ // function to send data to TTN
  
  byte payload[16];
  
  payload[0] = year-2000; 
  payload[1] = month;
  payload[2] = day; 
  payload[3] = hour;
  payload[4] = minute;
  payload[5] = second;
  payload[6] = Pow/256;
  payload[7] = Pow%256;
  payload[8] = WR1/256;
  payload[9] = WR1%256;
  payload[10] = WR2/256;
  payload[11] = WR2%256;
  payload[12] = WR3/256;
  payload[13] = WR3%256;
  payload[14] = int(Temp*100)/256;
  payload[15] = int(Temp*100)%256;

  modem.setPort(3);
  modem.beginPacket();
  modem.write(payload, sizeof(payload));   
  modem.endPacket(false);
  OLEDlms(" Send OK "); 
  delay(3000);
}
