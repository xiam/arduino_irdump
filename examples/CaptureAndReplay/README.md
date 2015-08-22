# Example project for IRDump

This is an example project for the [IRDump][1] library. Throughout this example
you'll learn to decode and replay a raw IR signal emmited by a remote
controller.

You may also want to check out the [Apple Remote][2] library which provides a
higher level of abstraction for an specific remote controller.

## Hardware

### Prerequisites

1. Arduino board (Arduino UNO, for instance).
2. Mini bread board.
3. Red LED.
4. IR LED.
5. IR sensor (A common TSOP 1838 will do).
6. Two 220 omh resistors.
7. A few unsorted male jumper wires.

![ir debugger_schem](https://cloud.githubusercontent.com/assets/385670/8024875/d7e5d17e-0d08-11e5-954f-af6d09f92782.png)

### Instructions

1. Wire the short leg of the IR LED to the Arduino's pin `~3`.
2. The long leg of the IR LED goes to Arduinos 5V through one of the 220omh
   resistors.
3. Place the IR Sensor into the breadboard and wire its `GND` and `5V` pins to
   the Arduino.
4. Wire the signal output of the IR Sensor to the Arduino's pin `2`.

We have a finished circuit now but since we can't see the IR light it will be
nice to have some sort of debugging mechanism, this is why we need the red LED:

1. Wire the long leg of the LED to 5V.
2. Connect the other leg to the IR Sensor's signal output through the other
   resistor.

![ir debugger_bb](https://cloud.githubusercontent.com/assets/385670/8024874/d7e5d19c-0d08-11e5-9009-60b369772bb8.png)

This is an actual picture of the finished circuit. Please note that the order
of the pins is not identical of that of the diagrams, the reason is that we are
using a TSOP 1838 sensor and it just happen to have a different pin
distribution. Make sure to take a look at your sensor's vendor datasheet before
start wiring things up.

![ir debugger_picture](https://cloud.githubusercontent.com/assets/385670/8024906/3774e5a2-0d0a-11e5-8785-e1bf2faaa0dc.jpg)

## Software

### Prerequisites

1. [Arduino IDE 1.6+][3].

### Getting up a project copy

You'll need a remote controller for this test, I am using an Apple Remote, if
you don't have one you can try with other remote controllers you'll probably
have to edit `SIGNAL_MAX_SIZE` and `PULSE_MAX_LENGTH` to tweak the capture
parameters.

1. Install the [IRDump][1] library.
2. Open the `CapturaAndReplay.ino` file with the Arduino IDE.
3. Verify and upload the code to the board.
4. Click the "Serial Monitor" command in the Arduino's IDE tools menu to bring
   on the serial monitor.
5. Change the baud rate to `115200 baud`.

Now we're ready to continue, point a remote controller to the IR sensor and
press any key to see its code! You'll see something like this:

```
Point an infrared remote controller to your sensor and press any button.
A wild IR signal appeared!
/* Begin signal. */
unsigned int signal[] = {
	9108, 4488,
	548, 564,
	540, 1680,
	540, 1672,
	548, 1668,
	540, 568,
	540, 1676,
	544, 1676,
	540, 1672,
	544, 1672,
	548, 1672,
	544, 1668,
	548, 560,
	544, 568,
	540, 564,
	540, 568,
	536, 1672,
	548, 564,
	544, 1668,
	548, 564,
	548, 560,
	548, 560,
	540, 568,
	540, 568,
	536, 568,
	540, 1680,
	540, 1676,
	540, 1672,
	552, 1668,
	548, 564,
	548, 560,
	544, 1664,
	548, 1692,
	540, 0
};
/* End of signal (67 pulses) */
Waiting 5 secs before replaying...
Replaying captured signal...
Done
```

The signal that is shown in the log corresponds to the unique combination of
the pressed key of the remote control, you can also use the captured signal to
make the IR LED emit a pulse that is equivalent to the one you captured.

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

[1]: https://github.com/makerworkshop/arduino_irdump
[2]: https://github.com/makerworkshop/arduino_apple_remote
[3]: http://www.arduino.cc/en/Main/Software
