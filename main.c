#include "WProgram.h"

void yield(void){
}

void npx_init(void);
void rainbow(void);

void main(void)
{
	npx_init();
	for (;;)
		rainbow();
}
