#include "cmsis.h"
#define COUNT_TIMES (0x500000)

int main()
{
	//target LED: blue led, on PTB21
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; //enable port b clock gate control
	PORTB_PCR21 = 0x100;        // set PTB21 pin mux as gpio, see K64-sub family reference manual p.282
	GPIOB_PDDR |= (1 << 21);	// set PTB21 as GPIO output

	volatile unsigned int counter = 0;
	for(;;){
		/*
		for(counter = 0; counter < 0x200000; counter++);
		GPIOB_PTOR |= (1 << 21);	//toggle PTB21
		*/
		for(counter = 0; counter < COUNT_TIMES; counter++);
		GPIOB_PSOR |= (1 << 21);	//set PTB21
		for(counter = 0; counter < COUNT_TIMES; counter++);
		GPIOB_PTOR |= (1 << 21);	//clear PTB21
	}
	return 0;
}
