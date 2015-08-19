# IRDump library for Arduino

The IRDump library provides utility functions for sending and receiving
infrared pulses, using this library you can sniff some signals sent by infrared
remote controllers and craft your own signals too!

## Usage

```c++
class IRDump {
public:
  IRDump();

  // Match returns true if the given signal `b` matches `a`. A `threshold`
  // defined the error tolerance for each element of `a` and `b`.
  bool Match(unsigned int *a, unsigned int *b, int threshold);

  // Capture reads data from the IR sensor given by `pin` and writes it to the
  // `signal` array. The user must define the maximum number of pulses this
  // signal will have (`maxPulses`) and the maximun lenght of each pulse
  // (`pulseMaxLength`) in milliseconds.
  bool Capture(int pin, unsigned int *signal, int maxPulses, int pulseMaxLength);

  // Emit sends a signal using the IR LED given by `pin` at a custom frequency
  // (`kHz`).
  void Emit(int pin, unsigned int *signal, int kHz);
};
```

## Example project

See [arduino_irdump_example][3] for a fully working example project.

## How to install

1. Download the latest [.ZIP package][1].
1. From the *Sketch* > *Include Library* menu of the Arduino IDE choose *Add
   .ZIP Library...*.
1. Browse for the .ZIP file you've just downloaded.
1. After the installation, you'll be able to include the header's library
   easily from the *Sketch* > *Include Library* menu, just look for the new
   *IRDump* action under *Contributed libraries*.

## Acknowledgements

I went through these sources while learning how IR sensors and emitters work:

* http://learn.adafruit.com/ir-sensor/
* https://github.com/shirriff/Arduino-IRremote
* http://en.wikipedia.org/wiki/Apple_Remote
* http://techdocs.altium.com/display/ADRR/NEC+Infrared+Transmission+Protocol

The code used for emitting signals was taken from the
[Arduino-IRremote](https://github.com/shirriff/Arduino-IRremote) library, with
some minor modifications.

## License

> The MIT License (MIT)
>
> Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
>
> Permission is hereby granted, free of charge, to any person obtaining
> a copy of this software and associated documentation files (the
> "Software"), to deal in the Software without restriction, including
> without limitation the rights to use, copy, modify, merge, publish,
> distribute, sublicense, and/or sell copies of the Software, and to
> permit persons to whom the Software is furnished to do so, subject to
> the following conditions:
>
> The above copyright notice and this permission notice shall be
> included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
> EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
> MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
> NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
> LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
> OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
> WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[1]: https://github.com/makerworkshop/arduino_irdump/archive/master.zip
[2]: http://www.arduino.cc/en/guide/libraries
[3]: https://github.com/makerworkshop/arduino_irdump_example
