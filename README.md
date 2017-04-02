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

## Example projects

* [CaptureAndReplay][3] shows how to intercept and replay IR signals.
* [Arduino Hexbug Spider](https://github.com/xiam/arduino_hexbug_spider) shows
  how to control an Hexbug Spider with Arduino and an IR LED.

## How to install

Download the latest [.ZIP package][1] and follow the official instructions on
[importing a .ZIP library][2].

If you're planning to hack on this library you can also clone this repo
directly into your Arduino's library directory:

```
cd ~/Documents/Arduino/libraries
git clone https://github.com/xiam/arduino_hexbug_spider.git
```

You can find this path on the Preferences dialog of Arduino IDE.

![screen shot 2017-04-02 at 12 10 27](https://cloud.githubusercontent.com/assets/385670/24589267/6a50bc54-179d-11e7-8d90-abb52d1a6f75.png)


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
> Copyright (c) 2014-today José Carlos Nieto, https://menteslibres.net/xiam
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
[3]: examples/CaptureAndReplay
