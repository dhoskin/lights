#include "WProgram.h"

void internal_led(void);
void internal_led_init(void);

void yield(void)
{
}

int main(void)
{
	internal_led_init();
	for (;;)
		internal_led();
}
