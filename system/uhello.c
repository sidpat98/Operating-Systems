/* uhello.c - uhello */
#include <xinu.h>

void uhello(void){
	asm("INT $35"); //trigger interupt
	return;
}