# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
# ps2siotest

EE_BIN = ps2siotest.elf
EE_OBJS = main.o
EE_LIBS =  -lc -lgcc -ldebug

EE_ASFLAGS = -march=r5900 -EL

EE_CFLAGS = -march=r5900 -ffreestanding -fno-builtin -fshort-double -mno-memcpy -nostartfiles -nodefaultlibs -mlong64 -mhard-float -mno-abicalls -EL

# Strip debug info., but leave some symbols 
EE_LDFLAGS += $(LDPARAMS) -s 

###################################################################### 
# 

all: $(EE_BIN) 

clean:
	rm -f $(EE_OBJS) $(EE_BIN) 

rebuild: clean all

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
