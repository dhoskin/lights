# Christmas Lights SDK

## Colour format

The lights expect 8 bits per channel, MSB first.
Depending on the strip there are either 3 or 4 channels, for 24 or 32 bpp.

The exact format is configurable by the PX and BPP parameters.
Contrary to established practice, the B in BPP here is bytes not bits.
This parameter should be renamed CHANNELS.

The large strip has PX=150 and BPP=3, for colour format GRB.
This is the default.

A small test strip has PX=8 and BPP=4, for colour format GRBW.

## Dependencies

This repository uses git submodules.  After you clone it, please run

    $ git submodule init
    $ git submodule update

to fetch the teensy SDK.

You will need the arm-none-eabi toolchain and newlib.

OpenBSD packages: `arm-none-eabi-gcc-linaro`, `arm-none-eabi-newlib`, `teensyloader`

Ubuntu packages: `gcc-arm-none-eabi` and `libnewlib-arm-none-eabi`.

Arch packages: `arm-none-eabi-gcc` and `arm-none-eabi-newlib`.

To install it to the microcontroller you will need
[teensyloader](https://github.com/PaulStoffregen/teensy_loader_cli).

## Alternate toolchain

Alternatively to all of this, you can use
[Teensyduino](http://www.pjrc.com/teensy/teensyduino.html)
and the
[Neopixel](https://github.com/adafruit/Adafruit_NeoPixel)
library.

## Security

Yes, you can program it to implement a USB keyboard device and powertype `sudo rm -rf /` 100 times a second.

Please don't.
