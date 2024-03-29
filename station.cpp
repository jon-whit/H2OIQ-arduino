#include <Arduino.h>
#include <Servo.h>
#include <XBee.h>
#include "station.h"

Servo actuator;

// begin: private member functions

/*
 * Actuates the onboard servo into the position specified by the input
 * parameter.
 *
 * :param pos: Indicates the position the onboard servo should be set to.
 * Either on (true) or off (false).
 */
void station::actuate_servo(bool pos)
{

}

// end: private member functions

// begin: public member funtions
station::station(int id, XBee xbee, Servo s)
{
  _station_id = id;
  _xbee = xbee;
  _servo = s;
}

station::~station()
{

}

/*
 * Attempts to register this watering station with the H2OIQ server.
 *
 * PRECONDITION: This station's XBee serial device must be communicating with
 * the H2OIQ server properly.
 *
 * :return: True if registration was successful. False otherwise.
 */
bool station::register_station()
{
  return false;
}

void station::start_watering()
{

}

void station::stop_watering()
{

}

int station::read_moisture()
{
  return 1;
}

// end: public member functions
