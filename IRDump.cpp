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

void IRDump::Emit(int irLedPin, unsigned int *signal, int kHz)
{

  TIMER_DISABLE_INTR;

  pinMode(irLedPin, OUTPUT);
  digitalWrite(irLedPin, LOW);

  TIMER_CONFIG_KHZ(kHz);

  for (int pulse = 0; signal[pulse] > 0; pulse++) {
    if (pulse%2 == 0) {
      TIMER_ENABLE_PWM;
    } else {
      TIMER_DISABLE_PWM;
    }
    delayMicroseconds(signal[pulse]);
  }

  TIMER_DISABLE_PWM;
}

bool IRDump::Capture(int irSensorPin, unsigned int *signal, int maxPulses, int pulseMaxLength)
{
  unsigned int t, lt;
  bool mark;

  int capturingType = LOW;
  pinMode(irSensorPin, INPUT);

  mark = (digitalRead(irSensorPin) == capturingType);

  if (mark) {
    for (int pulse = 0; pulse < maxPulses; pulse++) {
      t = micros();
      while (digitalRead(irSensorPin) == capturingType) {
        lt = micros();
        if ((lt - t) > pulseMaxLength) {
          signal[pulse] = 0;
          return true;
        };
      }
      capturingType = !capturingType;
      signal[pulse] = lt - t;
    }
  }

  return false;
}

bool IRDump::Match(unsigned int *signal, unsigned int *input, int threshold)
{
  unsigned int diff;
  int i;

  for (i = 0; signal[i] > 0 && input[i] > 0; i++) {
    if (signal[i] > input[i]) {
      diff = signal[i] - input[i];
    } else {
      diff = input[i] - signal[i];
    }

    if (diff > threshold) {
      return false;
    }
  }

  if (i < 1) {
    return false;
  }

  return true;
}
