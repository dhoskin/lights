#include "core_pins.h"

void npx_show(const unsigned char *buf, int n);

/* 
 * Bastardized HSV formula. H__ with SV uncontrolled.
 * https://en.wikipedia.org/wiki/HSV_color_space#From_HSV
 */

static void hue2rgb(unsigned char *p, unsigned char hue)
{
	const unsigned char fullchroma = ((1 << 5) - 1);
	unsigned char r, g, b;
	unsigned char sector = hue >> 5;
	unsigned char x = hue & fullchroma;

	switch (sector) {
	case 0:
		r = fullchroma;
		g = x;
		b = 0;
		break;
	case 1:
		r = fullchroma - x;
		g = fullchroma;
		b = 0;
		break;
	case 2:
		r = 0;
		g = fullchroma;
		b = x;
		break;
	case 3:
		r = 0;
		g = fullchroma - x;
		b = fullchroma;
		break;
	case 4:
		r = x;
		g = 0;
		b = fullchroma;
		break;
	case 5:
		r = fullchroma;
		g = 0;
		b = fullchroma - x;
		break;
	default:
		r = 0;
		g = 0;
		b = 0;
		break;
	}

	*p++ = g;
	*p++ = r;
	*p++ = b;
#if BPP == 4
	*p++ = 0;
#endif
}		

static void copypx(unsigned char *src, unsigned char *dst)
{
	int i;

	for (i = 0; i < BPP; ++i)
		*dst++ = *src++;
}
	

static void shift(unsigned char *buf)
{
	int i;

	for (i = (PX * BPP) - 1; i > 0; i -= BPP)
		copypx(&buf[i - BPP], &buf[i]);
}

void rainbow(void)
{
	static unsigned char buf[PX * BPP];
	unsigned char hue;

	for (hue = 0; hue < (6 << 5); ++hue) {
		hue2rgb(buf, hue);
		npx_show(buf, sizeof buf);
		delay(32);
		shift(buf);
	}
}
