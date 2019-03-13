/* ready.c - ready */

#include <xinu.h>

qid16	readylist;			/* Index of ready list		*/

/*------------------------------------------------------------------------
 *  ready  -  Make a process eligible for CPU service
 *------------------------------------------------------------------------
 */
status	ready(
	  pid32		pid		/* ID of process to make ready	*/
	)
{
	register struct procent *prptr;

	if (isbadpid(pid)) {
		return SYSERR;
	}

	/* Set process state to indicate ready and add to ready list */

	prptr = &proctab[pid];
	prptr->prstate = PR_READY;
	prptr->prvcputime = proctab[firstid(readylist)].prvcputime; /*given value of the first id in the ready list */
	prptr->prcputime = proctab[firstid(readylist)].prcputime; /*given value of the first id in the ready list */
	insert(pid, readylist, prptr->prprio);
	resched();

	return OK;
}
