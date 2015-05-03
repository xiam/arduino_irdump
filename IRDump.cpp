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

#include <IRDump.h>

IRDump::IRDump()
{

}

bool IRDump::Capture(int pin, int minLength, int maxLength, unsigned int **signal, int maxPulses)
{
  int pulse;
  unsigned long t, lt;
  bool mark;
  bool capturing;

  // pinMode(pin, INPUT);

  capturing = false;

  do {
    mark  = (digitalRead(pin) == LOW);
    Serial.println(mark);

    t = micros();
    if (mark) {

      if (!capturing) {
        capturing = true;
        pulse = 0;
        (*signal)[pulse] = 0;
        lt = 0;
      }

      // Odd pulses are for marks only.
      if ((pulse % 2 != 0) || (*signal)[pulse] > maxLength) {
        if ((*signal)[pulse] >= minLength) {
          // Next signal.
          (*signal)[++pulse] = 0;
        }
      }
    } else {
      // Even pulses are for spaces only.
      if ((pulse % 2 == 0) || (*signal)[pulse] > maxLength) {
        if ((*signal)[pulse] >= minLength) {
          // Next signal.
          (*signal)[++pulse] = 0;
        }
      }
    }
    if (pulse < maxPulses) {
      if (lt > 0) {
        (*signal)[pulse] += t - lt;
      }
      lt = t;
    } else {
      // Capture ended.
      return true;
    }
  } while (capturing);

  return false;
}
