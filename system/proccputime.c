/* proccputime.c - proccputime */

#include <xinu.h>

/*------------------------------------------------------------------------
 * proccputime - tells the cpu time of a process
 *------------------------------------------------------------------------*/
 

syscall proccputime(pid32 pid){
	struct	procent	*prptr;	
	intmask 	mask;    	/* Interrupt mask		*/

	mask = disable();
	uint32 timecpu;
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}
	prptr = &proctab[pid];
	timecpu = prptr->prcputime; 

	 if(pid == currpid){
	 	timecpu = prptr->prcputime + (QUANTUM - preempt);
	 }

	//kprintf("timecpu is: %d", timecpu);
	
	return timecpu;
}