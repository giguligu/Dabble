/* If your smartphone has Barometer sensor support then this code helps in accessing that sensor's value through Dabble app.
   NOTE:
   1)For Arduino Mega Connect Bluetooth on Serial3 pins.
   2)For Arduino Uno/Nano library uses SoftwareSerial,hence pin 2 and pin 3 are used
   as RX and TX pins respectively on SoftwareSerial.Hence with arduino Uno
   follow below connections for bluetooth.
   UNO  - BLUETOOTH
   2    - TX
   3    - RX

   3)For Uno/Nano keep bluetooth Baudrate below 38400.
   Explore more on: https://thestempedia.com/docs/dabble/phone-sensors-module/
*/

#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <Dabble.h>


void setup() {
  Serial.begin(250000);
  Dabble.begin(9600);  //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  print_Barometer_data();
}

void print_Barometer_data()
{
  Serial.print("Barometer: ");
  Serial.println(Sensor.getdata_Barometer(), 7);
  Serial.println();
}


