#include <xinu.h>

void appio(void){
	
	int x, y; 
	x = 0; 
	y = clktimefine; 
	while(clktimefine - y < 29000) { 
	   x++; 
	   sleepms(20); 
	} 
	kprintf("io-bound: %d %d %d\n", currpid, x, proctab[currpid].prcputime); 
}