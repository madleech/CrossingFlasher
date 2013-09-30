/**
 * On and Off
 * ==========
 * Loops doing the following:
 * 0 to 2 seconds: off
 * 2 to 10 seconds: flashing
 * 10 seconds: back to start
 * 
 * For more info, see http://utrainia.michael.net.nz/46-simulating-railroad-crossing-lights
 */

#include <CrossingFlasher.h>

CrossingFlasher bucks(2, 3);

void setup() {
}

int timer = 0;

void loop() {
  // turn off after 10 seconds
  if (timer >= 10000) {
    bucks.off();
    timer = 0;
  }
  // turn on for 2 seconds
  else if (timer >= 2000)
    bucks.on();
  
  delay(1);
  timer ++;
  
  bucks.update();
}
