// Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

/*
 * Aknowledgements:
 *
 * I used these sources while learning how IR sensors and emitters work:
 *
 *  http://learn.adafruit.com/ir-sensor/
 *  https://github.com/shirriff/Arduino-IRremote
 *  http://en.wikipedia.org/wiki/Apple_Remote
 *  http://techdocs.altium.com/display/ADRR/NEC+Infrared+Transmission+Protocol
 *
 * The code used for emitting signals was taken from the Arduino-IRremote
 * library, with some minor modifications.
 * See https://github.com/shirriff/Arduino-IRremote
 *
 * */

#ifndef MAKERWORKSHOP_IRDUMP
#define MAKERWORKSHOP_IRDUMP

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class IRDump {
public:
  IRDump();
  bool Capture(int pin, int minLength, int maxLength, unsigned int **signal, int maxPulses);
};

#endif
