/* uchprio.c - uchprio */

#include <xinu.h>

/*--------------------------------------------------------------------------------
 *  uchprio  -  Change the scheduling priority of a process without invoking trap
 *--------------------------------------------------------------------------------
 */
pri16	uchprio(
	  pid32		pid,		/* ID of process to change	*/
	  pri16		newprio		/* New priority			*/
	)
{
	int oldprio;
	int newprio1=newprio;
	asm("movl %1, %%ebx \n\t" 
		"movl %2, %%ecx \n\t"
		"int $36 \n\t"
		"movl %%eax, %0"
		: "=r" (oldprio)
		: "r" (pid), "r"(newprio1)
		: "ebx", "ecx");
	return oldprio;
}
