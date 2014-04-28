/*
The sketch is an empty template for Bluetooth Low Energy 4.
Simply remove what you dont need, and fill in the rest.
*/

#include <RFduinoBLE.h>

void setup()
{
  RFduinoBLE.deviceName = "PO";
  RFduinoBLE.advertisementData = "Bam";
//  RFduinoBLE.advertisementInterval = MILLISECONDS(300);
  RFduinoBLE.txPowerLevel = -20;  // (-20dbM to +4 dBm)

  // start the BLE stack
  //RFduinoBLE.begin();
  //delay(100);
  Serial.begin(57600);
//  Serial.println("Begin");
}

char data[20];

void loop()
{
     RFduino_ULPDelay(SECONDS(1));  

  // to send one char
  // RFduinoBLE.send((char)temp);
  sprintf(data,"%04d",millis()/1000);
  // to send multiple chars
   Serial.print(data);
   //RFduinoBLE.send(data[3]);
//   delay(1000);

}

void RFduinoBLE_onAdvertisement(bool start){
  Serial.println("Advert");
}

void RFduinoBLE_onConnect(){
  Serial.println("Connect");
}

void RFduinoBLE_onDisconnect(){
    Serial.println("Disconnect");

}

// returns the dBm signal strength indicated by the receiver after connection (-0dBm to -127dBm)
void RFduinoBLE_onRSSI(int rssi){
}

void RFduinoBLE_onReceive(char *data, int len){
  Serial.println("onReceive");
}
