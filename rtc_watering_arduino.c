//             Herbal garden watering project                //
/* 
 The followign part of the code is from https://create.arduino.cc/projecthub/robotgeek-projects-team/using-a-real-time-clock-with-arduino-6b3896 
 and from http://www.instructables.com/id/How-to-use-a-Buzzer-Arduino-Tutorial/
 */
#include <Wire.h>
#include "DS1307.h"

DS1307 clock;//define a object of DS1307 class

const int RELAY = 4; //Relay set to digital pin 4
const int buzzer = 9; //Buzzer set to digital pin 9

void setup()
{
  pinMode(RELAY, OUTPUT);
  clock.begin();
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}
void loop()
{
  timedRelay();
  tone(buzzer, 2000); // Send 2KHz sound signal...
  delay(500);        // ...for half sec
  noTone(buzzer);     // Stop sound...
  delay(500);        // ...for half sec
}

void timedRelay()
{
  clock.getTime();

  switch (clock.hour)
  {
    case 6: //when the clock reads 6 AM seconds (Once every 24 hours)
      digitalWrite(RELAY, HIGH);   // turn the Relay on (HIGH is the voltage level)
      delay(20000);              // wait for 20 second
      digitalWrite(RELAY, LOW);    // turn the Relay off by making the voltage LOW
      delay(3600000);              // wait for 3600 second
  }

   switch (clock.hour)
  {
    case 20: //when the clock reads 8 PM seconds (Once every 24 hours)
      digitalWrite(RELAY, HIGH);   // turn the Relay on (HIGH is the voltage level)
      delay(20000);              // wait for 20 second
      digitalWrite(RELAY, LOW);    // turn the Relay off by making the voltage LOW
      delay(3600000);              // wait for 3600 second
  }
}
