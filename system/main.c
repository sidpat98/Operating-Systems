
/*  main.c  - main */

#include <xinu.h>

/*
extern void myapp(void);

 process main(void){
   
	//Run the Xinu shell 
	recvclr();
	resume(create((void *)myapp, 8192, 50, "myapp", 1, CONSOLE));
	return OK;
    
}
*/

void sndA(void), sndB(void);

void main(void) {
resume( create(sndA, 1024, 20, "process 1", 0) );
//procinfo(4);
resume( create(sndB, 1024, 20, "process 2", 0) );
//procinfo(5);

}

/*------------------------------------------------------------------------ 
* sndA - Repeatedly emit ’A’ on the console without terminating 
*------------------------------------------------------------------------ */
void sndA(void) {
	while( 1 )
	kprintf("A");
}

/*------------------------------------------------------------------------ * 
sndB - Repeatedly emit ’B’ on the console without terminating 
*------------------------------------------------------------------------ */
void sndB(void) {
while( 1 )
kprintf("B");
}


