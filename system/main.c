/*  main.c  - main */

#include <xinu.h>
    
  extern void appcpu(void);
  extern void appio(void);
  extern void bonusapp(void);

void main(void)
{
  #if XTESTA
  resume (create(appcpu, 1024, 20, "appcpu1", 0));  
  resume (create(appcpu, 1024, 20, "appcpu2", 0));  
  resume (create(appcpu, 1024, 20, "appcpu3", 0));  
  resume (create(appcpu, 1024, 20, "appcpu4", 0));  
  resume (create(appcpu, 1024, 20, "appcpu5", 0));  
#endif	

#if XTESTB
  resume (create(appio, 1024, 20, "appio1", 0));  
  resume (create(appio, 1024, 20, "appio2", 0));  
  resume (create(appio, 1024, 20, "appio3", 0));  
  resume (create(appio, 1024, 20, "appio4", 0));  
  resume (create(appio, 1024, 20, "appio5", 0));  
#endif  

#if XTESTC
  resume (create(appcpu, 1024, 20, "appcpu1", 0));  
  resume (create(appcpu, 1024, 20, "appcpu2", 0));  
  resume (create(appcpu, 1024, 20, "appcpu3", 0));  
  resume (create(appcpu, 1024, 20, "appcpu4", 0));  
  resume (create(appcpu, 1024, 20, "appcpu5", 0));  
  resume (create(appio, 1024, 20, "appio1", 0));  
  resume (create(appio, 1024, 20, "appio2", 0));  
  resume (create(appio, 1024, 20, "appio3", 0));  
  resume (create(appio, 1024, 20, "appio4", 0));  
  resume (create(appio, 1024, 20, "appio5", 0));  
#endif  

#if XTESTD
  resume (create(appcpu, 1024, 20, "appcpu1", 0));
  sleepms(5);  
  resume (create(appcpu, 1024, 20, "appcpu2", 0)); 
  sleepms(5); 
  resume (create(appcpu, 1024, 20, "appcpu3", 0)); 
  sleepms(5); 
  resume (create(appcpu, 1024, 20, "appcpu4", 0)); 
  sleepms(5); 
  resume (create(appcpu, 1024, 20, "appcpu5", 0)); 
  sleepms(5);
#endif

#if XTESTBONUS
  resume (create(bonusapp, 1024, 20, "bonusapp1", 0));  
  resume (create(bonusapp, 1024, 20, "bonusapp2", 0));  
  resume (create(bonusapp, 1024, 20, "bonusapp3", 0));  
  resume (create(bonusapp, 1024, 20, "bonusapp4", 0));  
  resume (create(bonusapp, 1024, 20, "bonusapp5", 0));  
#endif 
}
