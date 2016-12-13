# Christmas Light SDK

## Dependencies

This repository uses git submodules.  After you clone it, please run

    $ git submodule init
    $ git submodule update

to fetch the teensy SDK.

You will need the arm-none-eabi toolchain and newlib.

OpenBSD packages: `arm-none-eabi-gcc-linaro` `arm-none-eabi-newlib` `teensyloader`

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
