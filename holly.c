#include "core_pins.h"

void npx_show(const unsigned char *buf, int n);

static void green(unsigned char *p)
{
	*p++ = 63;
	*p++ = 0;
	*p++ = 0;
#if BPP == 4
	*p++ = 0;
#endif
}

static void red(unsigned char *p)
{
	*p++ = 0;
	*p++ = 63;
	*p++ = 0;
#if BPP == 4
	*p++ = 0;
#endif
}

static void white(unsigned char *p)
{
#if BPP == 4
	*p++ = 0;
	*p++ = 0;
	*p++ = 0;
	*p++ = 63;
#else
	*p++ = 31;
	*p++ = 31;
	*p++ = 15;
#endif
}

static void show(const unsigned char *buf, int n)
{
	npx_show(buf, n);
	delay(62);
}

void holly(void)
{
	static unsigned char buf[PX * BPP];
	int i;

	for (i = 0; i < PX * BPP; i += BPP)
		green(&buf[i]);

	for (i = 0; i < PX; ++i) {
		white(&buf[i * BPP]);
		show(buf, sizeof buf);
		if (i & 1)
			red(&buf[i * BPP]);
		else
			green(&buf[i * BPP]);
	}

	for (i = PX - 1; i >= 0; --i) {
		white(&buf[i * BPP]);
		show(buf, sizeof buf);
		green(&buf[i * BPP]);
	}
}
