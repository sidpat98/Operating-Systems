/* boost.c  - boost*/
//Allows current process to super charge its priority and time slice
#include <xinu.h>
//uint32	preempt;		// Preemption counter
uint32	preempt;		/* Preemption counter			*/

syscall boost(
	uint32 priob, //added to the priority
	uint32 timeb //msec added to time slice
	)
{

    //pid32 pid; //stores pid
	intmask	mask;			/* Saved interrupt mask		*/	
	struct	procent *prptr;
	//pri16	oldprio;		/* Priority to return		*/
	
	mask = disable(); // disable interupts

	if (priob < 0 || timeb < 0 || priob > 5 || timeb > 5) { //check bounds
		restore(mask); // enable interupts
		return SYSERR;
	}	

	#if XTEST
	kprintf("\nThe prioroty before boost is: %d\n", prptr->prprio);
	#endif
	#if XTEST
	kprintf("The time slice before boost is: %d\n", preempt);
	#endif
	
	//prptr = &proctab[pid];
	prptr->prprio = (priob + (prptr->prprio)); //add priob to the current priority
	#if XTEST
	kprintf("The upadted priority is %d\n", prptr->prprio); 
	#endif

	if((prptr->prprio)>100){ //check bounds
		restore(mask); // enable interupts
		return SYSERR;
	}

	preempt=preempt+timeb; //add time slice
	#if XTEST
	kprintf("The upadted time slice is %d\n", preempt); 
	#endif
	if(preempt>1000){ //check bounds
		restore(mask); // enable interupts
		return SYSERR;
	}
	


restore(mask); // enable interupts
	return OK;
}
