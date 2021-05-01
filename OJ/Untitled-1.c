/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Code by Simon Monk
 http://www.simonmonk.org
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Event_h
#define Event_h

#include <inttypes.h>

#define EVENT_NONE 0
#define EVENT_EVERY 1
#define EVENT_OSCILLATE 2

int count = 0;

class Event
{

public:
  Event(void);
  void update(void);
  void update(unsigned long now);
  int8_t eventType;
  unsigned long period;
  int repeatCount;
  uint8_t pin;
  uint8_t pinState;
  void (*callback)(void);
  unsigned long lastEventTime;
  int count;
};

#endif

#ifndef Timer_h
#define Timer_h

#include <inttypes.h>


#define MAX_NUMBER_OF_EVENTS (10)

#define TIMER_NOT_AN_EVENT (-2)
#define NO_TIMER_AVAILABLE (-1)

class Timer
{

public:
  Timer(void);

  int8_t every(unsigned long period, void (*callback)(void));
  int8_t every(unsigned long period, void (*callback)(void), int repeatCount);
  int8_t after(unsigned long duration, void (*callback)(void));
  int8_t oscillate(uint8_t pin, unsigned long period, uint8_t startingValue);
  int8_t oscillate(uint8_t pin, unsigned long period, uint8_t startingValue, int repeatCount);
  
  /**
   * This method will generate a pulse of !startingValue, occuring period after the
   * call of this method and lasting for period. The Pin will be left in !startingValue.
   */
  int8_t pulse(uint8_t pin, unsigned long period, uint8_t startingValue);
  
  /**
   * This method will generate a pulse of pulseValue, starting immediately and of
   * length period. The pin will be left in the !pulseValue state
   */
  int8_t pulseImmediate(uint8_t pin, unsigned long period, uint8_t pulseValue);
  void stop(int8_t id);
  void update(void);
  void update(unsigned long now);

protected:
  Event _events[MAX_NUMBER_OF_EVENTS];
  int8_t findFreeEventIndex(void);

};
#endif

//// YOUR CODE STARTS HERE

Timer t;
int pin13 = 13;
int pin12 = 12;
int pin11 = 11;
int pin10 = 10;

void setup()
{
  int condition = 0;
    Serial.begin(9600);
	pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin10, OUTPUT);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  //int count = 0;
  //delay(1000);
  
  	// starts from high, oscillates on the pin every 500ms
  
    int eventId13 = t.oscillate(pin10, 500, LOW);
    int eventId12 = t.oscillate(pin11, 1000, LOW);
    int eventId11 = t.oscillate(pin12, 2000, LOW);
    int eventId10 = t.oscillate(pin13, 4000, LOW);
    //int eventId130 = t.oscillate(pin13, 500, HIGH);
    //int eventId120 = t.oscillate(pin12, 1000, HIGH);
    //int eventId110 = t.oscillate(pin11, 2000, HIGH);
    //int eventId100 = t.oscillate(pin10, 4000, HIGH);
  	if (eventId13 < 0 || eventId12 < 0 || eventId11 < 0 || eventId10 < 0) {
      Serial.println("Could not initialize timer");
    }
    condition = 1;
    t.every(8000, stopAllTimers)
}


// 1 unit of your timer = 500ms in real time

void loop() {
    t.update();
  count++;
   // Serial.print("count = ");
    //Serial.println(count);
  
}

// "every" X milliseconds
void stopAllTimers() {
   t.stop();
  
}

//// YOUR CODE ENDS HERE

// For Arduino 1.0 and earlier
// #if defined(ARDUINO) && ARDUINO >= 100
// #include "Arduino.h"
// #else
// #include "WProgram.h"
// #endif

Event::Event(void)
{
	eventType = EVENT_NONE;
}

void Event::update(void)
{
    unsigned long now = millis();
    update(now);
}

void Event::update(unsigned long now)
{
	if (now - lastEventTime >= period)
	{
		switch (eventType)
		{
			case EVENT_EVERY:
				(*callback)();
				break;

			case EVENT_OSCILLATE:
				pinState = ! pinState;
				digitalWrite(pin, pinState);
				break;
		}
		lastEventTime = now;
		count++;
	}
	if (repeatCount > -1 && count >= repeatCount)
	{
		eventType = EVENT_NONE;
	}
}


Timer::Timer(void)
{
}

int8_t Timer::every(unsigned long period, void (*callback)(), int repeatCount)
{
	int8_t i = findFreeEventIndex();
	if (i == -1) return -1;

	_events[i].eventType = EVENT_EVERY;
	_events[i].period = period;
	_events[i].repeatCount = repeatCount;
	_events[i].callback = callback;
	_events[i].lastEventTime = millis();
	_events[i].count = 0;
	return i;
}

int8_t Timer::every(unsigned long period, void (*callback)())
{
	return every(period, callback, -1); // - means forever
}

int8_t Timer::after(unsigned long period, void (*callback)())
{
	return every(period, callback, 1);
}

int8_t Timer::oscillate(uint8_t pin, unsigned long period, uint8_t startingValue, int repeatCount)
{
	int8_t i = findFreeEventIndex();
	if (i == NO_TIMER_AVAILABLE) return NO_TIMER_AVAILABLE;

	_events[i].eventType = EVENT_OSCILLATE;
	_events[i].pin = pin;
	_events[i].period = period;
	_events[i].pinState = startingValue;
	digitalWrite(pin, startingValue);
	_events[i].repeatCount = repeatCount * 2; // full cycles not transitions
	_events[i].lastEventTime = millis();
	_events[i].count = 0;
	return i;
}

int8_t Timer::oscillate(uint8_t pin, unsigned long period, uint8_t startingValue)
{
	return oscillate(pin, period, startingValue, -1); // forever
}

/**
 * This method will generate a pulse of !startingValue, occuring period after the
 * call of this method and lasting for period. The Pin will be left in !startingValue.
 */
int8_t Timer::pulse(uint8_t pin, unsigned long period, uint8_t startingValue)
{
	return oscillate(pin, period, startingValue, 1); // once
}

/**
 * This method will generate a pulse of startingValue, starting immediately and of
 * length period. The pin will be left in the !startingValue state
 */
int8_t Timer::pulseImmediate(uint8_t pin, unsigned long period, uint8_t pulseValue)
{
	int8_t id(oscillate(pin, period, pulseValue, 1));
	// now fix the repeat count
	if (id >= 0 && id < MAX_NUMBER_OF_EVENTS) {
		_events[id].repeatCount = 1;
	}
	return id;
}


void Timer::stop(int8_t id)
{
	if (id >= 0 && id < MAX_NUMBER_OF_EVENTS) {
		_events[id].eventType = EVENT_NONE;
	}
}

void Timer::update(void)
{
	unsigned long now = millis();
	update(now);
}

void Timer::update(unsigned long now)
{
	for (int8_t i = 0; i < MAX_NUMBER_OF_EVENTS; i++)
	{
		if (_events[i].eventType != EVENT_NONE)
		{
			_events[i].update(now);
		}
	}
}
int8_t Timer::findFreeEventIndex(void)
{
	for (int8_t i = 0; i < MAX_NUMBER_OF_EVENTS; i++)
	{
		if (_events[i].eventType == EVENT_NONE)
		{
			return i;
		}
	}
	return NO_TIMER_AVAILABLE;
}