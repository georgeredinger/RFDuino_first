/*
BLE hello world
*/

#include <RFduinoBLE.h>

void setup()
{
  RFduinoBLE.deviceName = "T";
  RFduinoBLE.advertisementData = "Temp";
//  RFduinoBLE.advertisementInterval = MILLISECONDS(300);
  RFduinoBLE.txPowerLevel = -20;  // (-20dbM to +4 dBm)

  RFduinoBLE.begin();
 
//  Serial.begin(57600);
//  Serial.println("Begin"); // using Serial, make the BLE not work and using RFDUINOBLE makes Serial not work
}

char data[20];
float temp;
void loop()
{
     RFduino_ULPDelay(SECONDS(1));  
     temp = RFduino_temperature(FAHRENHEIT); // returns temperature in Celsius and stores in float temp 

 
  sprintf(data,"%04.1f",temp);
    RFduinoBLE.send(data,4);

}

void RFduinoBLE_onAdvertisement(bool start){
 // Serial.println("Advert");
}

void RFduinoBLE_onConnect(){
 // Serial.println("Connect");
}

void RFduinoBLE_onDisconnect(){
//    Serial.println("Disconnect");

}

// returns the dBm signal strength indicated by the receiver after connection (-0dBm to -127dBm)
void RFduinoBLE_onRSSI(int rssi){
}

void RFduinoBLE_onReceive(char *data, int len){
//  Serial.println("onReceive");
}
