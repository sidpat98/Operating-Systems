#include <xinu.h>

void appcpu(void){	

int x, y; 
x = 0; 
y = clktimefine; 
while(clktimefine - y < 29000) 
   x++; 
kprintf("cpu-bound: %d %d %d\n", currpid, x, proctab[currpid].prcputime); 

}