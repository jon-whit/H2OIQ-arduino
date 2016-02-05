/*
 * station.h - A library for H2OIQ watering stations.
 * Created by Jonathan Whitaker and Daniel Houston
 * Date: April 27, 2015
 */

#ifndef STATION_H
#define STATION_H

#include <Arduino.h>
#include <Servo.h>
#include <XBee.h>

const int MOISTURE_SENSOR = A0; // PC0 = A0 Signal Voltage
const int MOISTURE_VCC = 6;     // PD6 = D6 VCC for MoistureSensor
const int MOISTURE_GND = 8;     // PB0 = D8 GND for Moisture Sensor
const int MOISTURE_NONE = 550;  // Analog Voltage when no water
const int MOISTURE_FULL = 650;  // Analog Voltage when full water

const int CHIP_RESET = A2;      // PC2 = A2 Pin that resets the chip when held high.
const int XBEE_SLEEP = 3;       // PD3 the pin that tells the XBEE to either wake or sleep

// Servo constants
const int SERVO_SIGNAL = 5;     // PD5 = D5
const int SERVO_POWER =  2;     // PB7 = D21 to turn on Servo power
const int SERVO_OFF_POS = 180;
const int SERVO_ON_POS = 90;

// Button and LED constants
const int LED = 9;	        // PB1 = D9 LED for button
const int BUTTON_UR = 10;	// PB2 = D10 Button
const int BUTTON_LR = 11;	// PB3 = D11 Button
const int BUTTON_UL = 12;	// PB4 = D12 Button
const int BUTTON_LL = 13;	// PB5 = D13 Button

// Battery Monitoring
const int  pSDA = A4;           //PC4 = A4  for two-wire signal
const int  pSCL =  A5;          //PC5 = A5  for two-wire clock
const int  BATT_VOLTAGE =  A3;  //PC3 = A3  Battery Voltage Pin

class station {

private:
  // private member variables
  XBee _xbee;
  Servo _servo;
  int _station_id;
  int _battery_life;

  // private member functions
  void actuate_servo(bool);

public:

  // public constructor and destructor
  station(int, XBee, Servo);
  ~station();

  // public member functions
  bool register_station();
  void start_watering();
  void stop_watering();
  int read_moisture();

  // relational operators
  inline bool operator< (const station& rhs) const {return _station_id < rhs._station_id;}
  inline bool operator> (const station& rhs) const {return _station_id > rhs._station_id;}
  inline bool operator<=(const station& rhs) const {return !(_station_id > rhs._station_id);}
  inline bool operator>=(const station& rhs) const {return !(_station_id < rhs._station_id);}
  inline bool operator==(const station& rhs) const { return _station_id == rhs._station_id; }
  inline bool operator!=(const station& rhs) const {return _station_id != rhs._station_id;}

};

 #endif
