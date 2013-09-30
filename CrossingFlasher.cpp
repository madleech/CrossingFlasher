/*
	CrossingFlasher - a small library for Arduino that simulates railway crossing lights, 
	as you might expect to see at a railroad crossing.
	Copyright (C) 2012 Michael Adams (www.michael.net.nz)
	All rights reserved.
	
	Permission is hereby granted, free of charge, to any person obtaining a 
	copy of this software and associated documentation files (the "Software"), 
	to deal in the Software without restriction, including without limitation 
	the rights to use, copy, modify, merge, publish, distribute, sublicense, 
	and/or sell copies of the Software, and to permit persons to whom the 
	Software is furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included 
	in all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
	SOFTWARE.
*/

#include "CrossingFlasher.h"
#include <Arduino.h>

CrossingFlasher::CrossingFlasher(int pin_a, int pin_b) 
	// store pins
: _pin_a(pin_a)
, _pin_b(pin_b)
	// set state
, _running(false)
, _flash_state(false)
, _next_flash(0)
{
	// set pins to outputs
	pinMode(_pin_a, OUTPUT);
	pinMode(_pin_b, OUTPUT);
}

void CrossingFlasher::on()
{
	if (_running) return; // only turn on once
	_running = true;
	_next_flash = millis();
	update();
}

void CrossingFlasher::update()
{
	if (!_running) return;
	if (millis() >= _next_flash) { // time to change outputs
		_next_flash = millis() + CROSSING_FLASHER_PERIOD; // when will the next flash happen
		digitalWrite(_pin_a, _flash_state);
		digitalWrite(_pin_b, !_flash_state);
		_flash_state = !_flash_state; // alternate outputs
	}
}

void CrossingFlasher::off()
{
	_running = false;
	digitalWrite(_pin_a, LOW);
	digitalWrite(_pin_b, LOW);
}
