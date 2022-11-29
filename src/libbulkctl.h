/*
 * libbulkctl.h - Bulk pin control library for Arduino.
 * 
 * Copyright (C) 2022 Kıvılcım Cemal Öztürk
 * Created November 29, 2022
 */
#ifndef LIBBULKCTL_H
#define LIBBULKCTL_H
#include "Arduino.h"

typedef int PIN_T; // type for pin.
typedef int VOLTAGE_T; // type for voltage.
typedef unsigned int DURATION_T; // type of duration.
typedef int MODE_T; // pin mode

void writePulse(PIN_T pin, DURATION_T timeout) { // Sets pin to HIGH, waits for timeout milliseconds, then sets the pin back to LOW.
	digitalWrite(pin, HIGH);
	delay(timeout);
	digitalWrite(pin, LOW);
}

void bulkWrite(size_t nPins, PIN_T *pins, VOLTAGE_T *values) { // assigns values to pins.
	for (size_t iota = 0; iota < nPins; iota++) {
		digitalWrite(*(pins + iota), *(values + iota));
	}
}

void bulkPinMode(size_t nPins, PIN_T *pins, MODE_T *modes) { // sets pins to modes.
	for (size_t iota = 0; iota < nPins; iota++) {
		pinMode(*(pins + i), *(modes + i));
	}
}
#endif
