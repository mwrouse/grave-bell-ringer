#include "Timing.h"

// Hardware Config
#define BELL_PIN          3

#define MIN_NUMBER_OF_RINGS   1
#define MAX_NUMBER_OF_RINGS   6
 


unsigned long randomDelay;
unsigned int numberOfRings;

void ringBell(unsigned int numberOfTimes);

void longDelay(long delayInMilliseconds);



void setup() {
  pinMode(BELL_PIN, OUTPUT);
  digitalWrite(BELL_PIN, LOW);

  pinMode(13, OUTPUT);
  delay(POWER_ON_DELAY);

  // Set bell to default state
  ringBell(1);
  
  randomSeed(analogRead(0));
}


void loop() {
  numberOfRings = random(MAX_NUMBER_OF_RINGS - MIN_NUMBER_OF_RINGS) + MIN_NUMBER_OF_RINGS;
  ringBell(numberOfRings);

  // Delay between next ring
  randomDelay = random(MAX_DELAY_BETWEEN_RINGS - MIN_DELAY_BETWEEN_RINGS) + MIN_DELAY_BETWEEN_RINGS;
  longDelay(randomDelay);
}



/**
 * Rings the bell
 */
void ringBell(unsigned int numberOfTimes) {
  digitalWrite(13, HIGH);
  
  for (unsigned int i = 0; i < numberOfTimes; i++) {
    // Ringing action
    digitalWrite(BELL_PIN, HIGH);
    delay(RELAY_DELAY);
    digitalWrite(BELL_PIN, LOW);

    // Ring gap if not the last ring
    if (i < (numberOfTimes - 1)) {
      delay(random(MAX_RING_GAP - MIN_RING_GAP) + MIN_RING_GAP);
    }

  }

  digitalWrite(BELL_PIN, LOW);
  digitalWrite(13, LOW);
}


/**
 * Long delay to avoid using delay() with a lot of time in it. This is better
 */
void longDelay(unsigned long delayInMilliseconds)
{
  unsigned long startTime = millis();
  unsigned long diff = 0;

  while(diff < delayInMilliseconds) {
    delay(50);
    digitalWrite(BELL_PIN, LOW);

    diff = (millis() - startTime);
  }
}
