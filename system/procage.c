/* procage.c - procage */

#include <xinu.h>

/*------------------------------------------------------------------------
 * procage - tells the age of a process
 *------------------------------------------------------------------------*/
 

syscall procage(pid32 pid){
	struct	procent	*prptr;	
	intmask 	mask;    	/* Interrupt mask		*/
	//uint32 clktimefine;
	//uint32 clktimefinebefore;
	uint32 final;

	mask = disable();

	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}

	prptr = &proctab[pid]; 
	//prptr->prbdate = clktimefine;
	//final = clktimefine - clktimefinebefore;
	//kprintf("the clktimefine is %d\n:", clktimefine - prptr->prbdate);
	restore(mask);
	return clktimefine - prptr->prbdate;
}