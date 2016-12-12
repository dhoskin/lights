#include "WProgram.h"

void onfor(int ms)
{
	digitalWriteFast(13, HIGH);
	delay(ms);
}

void offor(int ms)
{
	digitalWriteFast(13, LOW);
	delay(ms);
}

void internal_led(void)
{
	onfor(500);
	offor(500);
	onfor(250);
	offor(250);
	onfor(250);
	offor(250);
}

void internal_led_init(void)
{
	pinMode(13, OUTPUT);
}
