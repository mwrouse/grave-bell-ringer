/**
 * This file contains items related to timing of the bell ringing and the project
 */
#ifndef TIMING_H
#define TIMING_H

// Converting things to milliseconds
#define SecondsToMilliseconds(s)    ((unsigned long)s * 1000)
#define MinutesToMilliseconds(m)    (SecondsToMilliseconds(m * 60))




#define RELAY_DELAY       100

#define POWER_ON_DELAY    SecondsToMilliseconds(10)



#define MIN_DELAY_BETWEEN_RINGS   MinutesToMilliseconds(3)
#define MAX_DELAY_BETWEEN_RINGS   MinutesToMilliseconds(15)


// Ring gap is time between rings in a group of rings
#define MIN_RING_GAP    RELAY_DELAY
#define MAX_RING_GAP    500



#endif
