/*  main.c  - main */

#include <xinu.h>

extern void myapp(void);

 process main(void){
   
	//Run the Xinu shell 
	recvclr();
	resume(create((void *)myapp, 8192, 50, "myapp", 1, CONSOLE));
	return OK;
    
}

