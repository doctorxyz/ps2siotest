#include <tamtypes.h> 
#include <sifcmd.h>
#include <kernel.h>
#include <stdio.h>
#include <debug.h>
//#include <iopheap.h> 
//#include <loadfile.h> 
//#include <iopcontrol.h> 
//#include <fileio.h> 
//#include <compat.h> 
#include <sio.h> 

// Macros 
#define DEBUG 

#ifdef DEBUG 
#define dbgprintf(args...) printf(args) 
#define dbgscr_printf(args...) scr_printf(args) 
#else 
#define dbgprintf(args...) do { } while(0) 
#define dbgscr_printf(args...) do { } while(0) 
#endif 

int main(int argc, char *argv[]) 
{ 
  int ch; 

  // Not sure if this is still necessary, but doesn't appear to be done by ps2lib's "crt0" 
SifInitRpc(0); 

sio_init(38400, 0, 0, 0, 0);

  // Initialize screen display 
  init_scr(); 

  scr_printf("SIO Communications Tester v1.0 [2004-09-20] by tyranid, modified by redcoat\n\n"); 

  for(;;) { 
    ch = sio_getc(); 
    if(ch != -1) { 
      sio_putc(ch); 
      scr_printf("%c", (unsigned char)ch); 
      dbgprintf("%c", (unsigned char)ch); 
    } 
  } 

  return 0; 
} 
