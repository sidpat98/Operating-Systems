#include <xinu.h>

void bonusapp(void){
		int x, y; 
	x = 0; 
	y = clktimefine; 
	while(clktimefine - y < 29000) { 
	   x++; 
	   sleepms(20); 
	} 
	kprintf("io-bound: %d %d %d\n", currpid, x, procprio(currpid)); 

}