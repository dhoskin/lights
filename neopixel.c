#include "core_pins.h"
#include "kinetis.h"

/*
 * Timing comes from here:
 * https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.cpp
 */

void npx_init(void)
{
	pinMode(17, OUTPUT);
}

void npx_show(const unsigned char *buf, int n)
{
	int i;
	unsigned char mask;

	__disable_irq();

	for (i = 0; i < n; ++i) {
		for (mask = 1 << 7; mask > 0; mask >>= 1) {
			digitalWriteFast(17, HIGH);
			asm("nop; nop; nop; nop; nop; nop; nop; nop;");
			if (buf[i] & mask) {
				asm(
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop;");
			}
			digitalWriteFast(17, LOW);
			asm("nop; nop; nop; nop; nop; nop; nop; nop;");
			if (!buf[i] & mask) {
				asm(
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop;");
			}
		}
	}

	__enable_irq();
}
