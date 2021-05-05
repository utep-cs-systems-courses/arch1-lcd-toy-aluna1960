COMMON_OBJECTS  =
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/


CC		= msp430-elf-gcc
AS		= msp430-elf-gcc -mmcu=${CPU} -c
#AR              = msp430-elf-ar



OBJECTS         = p2switches.o switches.o lcddraw.o lcdutils.o main.o



libp2sw.a: $(OBJECTS)

	$(AR) crs $@ $^


$(OBJECTS): p2switches.h switches.h lcddraw.h lcdutils.h



all: lastOne.elf



#additional rules for files



lastOne.elf: ${COMMON_OBJECTS} main.o lcddraw.o lcdutils.o wdt_handler.o buzzer.o p2switches.o stateMachines.o switches.o libp2sw.a led.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lShape -lCircle -lp2sw
#-lTimer -lLcd -L../lib



load: lastOne.elf

	msp430loader.sh lastOne.elf

	make clean



clean:

	rm -f *.o *.elf *~ *# *.a
