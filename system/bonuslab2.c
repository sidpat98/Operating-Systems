

/* bonuslab2 -- procinfo */

#include <xinu.h> 

uint32	preempt;		/* Preemption counter			*/

/*------------------------------------------------------------------------
 *  procinfo  -  gives information about the process
 *------------------------------------------------------------------------
 */
void procinfo(pid32 pid){
	intmask 	mask;	/* Interrupt mask		*/
	//pid32		pid;		/* Stores new process id	*/
	struct	procent	*prptr;		/* Pointer to proc. table entry */
	//uint32 *saddr; /* stack address */
	mask = disable(); //disable interrupts
	prptr = &proctab[pid]; 
	kprintf("\npid: %d\n", pid); 
	if (pid < 0 ) { //if currpid is negetive return syserr
		restore(mask);
		return SYSERR;
	}
	if (isbadpid(pid)) {
		restore (mask);
		return SYSERR;
	}

	kprintf("process state: %d\n", prptr->prstate); //print process state
	kprintf("priority: %d\n", prptr->prprio); //print priority
	kprintf("stack address: 0x0%x\n", prptr->prstkbase); //print stack address
	kprintf("parent pid: %d\n", prptr->prparent); //print parent id
	kprintf("Time slice: %d\n", preempt); //print time slice
	restore(mask); //enable interrupts

	return OK;
}
