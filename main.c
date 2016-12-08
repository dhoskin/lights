#include "WProgram.h"

void yield(void){
}

void npx_init(void);
void holly(void);

void main(void)
{
	npx_init();
	for (;;)
		holly();
}
