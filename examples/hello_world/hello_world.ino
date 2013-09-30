/**
 * Hello World
 * ===========
 * Simple demo that turns on the cross bucks and then flashes them for ever.
 * 
 * For more info, see http://utrainia.michael.net.nz/46-simulating-railroad-crossing-lights
 */

#include <CrossingFlasher.h>

CrossingFlasher bucks(2, 3);

void setup() {
  bucks.on();
}

void loop() {
  bucks.update();
}
