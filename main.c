#include "WProgram.h"

void yield(void){
}

/*
 * Timing comes from here:
 * https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.cpp
 */

void npx_one(void)
{
	digitalWriteFast(17, HIGH);
	asm(
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop;");
	digitalWriteFast(17, LOW);
	asm(
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop;");
}

void npx_zero(void)
{
	digitalWriteFast(17, HIGH);
	asm("nop; nop; nop; nop; nop; nop; nop; nop;");
	digitalWriteFast(17, LOW);
	asm(
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop; nop; nop; nop; nop;"
		"nop; nop; nop; nop; nop;");
}

static inline void npx_chan(int x)
{
	if (x) {
		npx_zero(); npx_zero(); npx_zero(); npx_zero();
		npx_zero(); npx_one(); npx_one(); npx_one();
	} else {
		npx_zero(); npx_zero(); npx_zero(); npx_zero();
		npx_zero(); npx_zero(); npx_zero(); npx_zero();
	}
}

static inline void npx_px(int r, int g, int b, int w)
{
	npx_chan(r);
	npx_chan(g);
	npx_chan(b);
//	npx_chan(w);
}

void npx(void)
{
	int x = 0, sign = 1;

	pinMode(17, OUTPUT);

	for(;;){
		delay(125);

		for(x = 0; x < 50; ++x){
			npx_px(1, 0, 0, 0);
			npx_px(0, 1, 0, 0);
			npx_px(0, 0, 1, 0);
		}

/*		npx_px(1, 0, x == 0, 0);
		npx_px(0, 1, x == 1, 0);
		npx_px(1, 0, x == 2, 0);
		npx_px(0, 1, x == 3, 0);
		npx_px(1, 0, x == 4, 0);
		npx_px(0, 1, x == 5, 0);
		npx_px(1, 0, x == 6, 0);
		npx_px(0, 1, x == 7, 0);

		x += sign;
		if (x <= 0) {
			sign = 1;
			x = 0;
		}
		if (x >= 7) {
			sign = -1;
			x = 7;
		}
*/
/*
		npx_px(0, 0, 1, 0);
		npx_px(0, 0, 0, 1);
		npx_px(1, 0, 0, 0);
		npx_px(0, 1, 0, 0);
		npx_px(0, 0, 1, 0);
		npx_px(0, 0, 0, 1);
*/
	}
}

void main(void)
{
	npx();
}
