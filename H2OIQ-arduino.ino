#include <XBee.h>
#include <Servo.h>
#include "station.h"

void setup() {
  int station_id = 1;
  
  Serial.begin(9600);
  Serial1.begin(9600);
  
  XBee xbee = XBee();
  xbee.setSerial(Serial1);
  
  Servo s = Servo();
  station st = station(station_id, xbee, s);

  bool station_registered = false;
  while (!station_registered)
  {
    // attempt to register this station
    station_registered = st.register_station();
    delay(1000); // delay 1s
  }
  
  // setup the I/O
}

void loop() {
  // put your main code here, to run repeatedly:

}
