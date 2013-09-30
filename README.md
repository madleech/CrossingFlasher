CrossingFlasher
===============

* Author: Michael Adams (<http://www.michael.net.nz>)
* Copyright (C) 2012 Michael D K Adams.
* Released under the MIT license.

CrossingFlasher is a small library for simulating railway/railroad crossing lights. It gives you a nice simple interface for turning on, running, and turning off the LEDs, while it handles all the timing in the background automatically.

For documentation and examples please see the [project blog][1].

[1]: http://utrainia.michael.net.nz/46-simulating-railroad-crossing-lights

Requirements
------------
* An Arduino -- http://arduino.cc/

Installation
------------
Download the ZIP archive (https://github.com/madleech/CrossingFlasher/zipball/master) and extract it to your Arduino folder under `libraries/CrossingFlasher`.

Restart the Arduino IDE and you should see in File > Examples > CrossingFlasher entires for 'hello world' and 'on and off'


Code Examples
-------------
Here is the 'hello\_world' example program, included in the download:

    #include <CrossingFlasher.h>
    
    CrossingFlasher bucks(2, 3);
    
    void setup() {
      bucks.on();
    }
    
    void loop() {
      bucks.update();
    }


This connects pins 2 and 3 to the flasher. Running `bucks.on()` will start the flashing, and `bucks.off()` will stop the flashing. During your main loop you need to call `bucks.process()` every few milliseconds to update the LEDs, although timing isn't particularly critical.

Documentation
-------------
**CrossingFlasher(int pin_a, int pin_b)**
Creates a new CrossingFlasher object. The two parameters are the Arduino pin numbers to use for each LED.

**void on()**
Tells the CrossingFlasher library to start flashing. This just sets the initial flags; to actually make the flashing happen, see the next function. You can call this function as often as you like; duplicate calls will not muck it up.

**void update()**
Call this function as often as you like to update the LEDs. If the LEDs have been in their present state long enough, it'll alternate them. Otherwise it quickly returns so as not to waste valuable processing power.

**void off**
Stops the LEDs from flashing. Subsequent calls to `update()` will do nothing until `on()` is called again.


License
-------
MIT license, see LICENSE file.