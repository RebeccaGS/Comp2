#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#EEL270 - Computacao II - Turma 2021/2
#Prof. Marcelo Luiz Drumond Lanza
#Autor:
#Descricao: arquivo GNUmakefile


OS = $(shell uname -s)

CC=gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALETO = ansi 
STANDARD = -ansi

ifeq ($(dialeto), ANSI)
DIALETO = ansi
STANDARD = -std=ansi
endif

ifeq ($(dialeto), C90)
DIALETO = c90
STANDARD = -std=c90
endif

ifeq ($(dialeto), C89)
DIALETO = c89
STANDARD = -std=c89
endif

ifeq ($(dialeto), C99)
DIALETO = c99
STANDARD = -std=c99
endif

ifeq ($(dialeto), C11)
DIALETO = c11
STANDARD = -std=c11
endif

DEBUG =

ifeq ($(debug), DEPURACAO)
DEBUG = -DDEPURACAO
endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)

LFLAGS = -Wall

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o

AULA0202AOBJS = aula0202.o aula0201a.o
AULA0202BOBJS = aula0202.o aula0201b.o
AULA0202COBJS = aula0202.o aula0201c.o
AULA0202DOBJS = aula0202.o aula0201d.o

AULA0302AOBJS = aula0302.o aula0301a.o
AULA0302BOBJS = aula0302.o aula0301b.o
AULA0302COBJS = aula0302.o aula0301c.o
AULA0302DOBJS = aula0302.o aula0301d.o

AULA0402AOBJS = aula0402.o aula0401a.o
AULA0402BOBJS = aula0402.o aula0401b.o
AULA0402COBJS = aula0402.o aula0401c.o
AULA0402DOBJS = aula0402.o aula0401d.o
AULA0404AOBJS = aula0404.o aula0403a.o
AULA0404BOBJS = aula0404.o aula0403b.o
AULA0404COBJS = aula0404.o aula0403c.o
AULA0404DOBJS = aula0404.o aula0403d.o
AULA0404EOBJS = aula0404.o aula0403e.o

AULA0502AOBJS = aula0502a.o aula0501.o
AULA0502BOBJS = aula0502b.o aula0501.o
AULA0503AOBJS = aula0503a.o aula0501.o
AULA0503BOBJS = aula0503b.o aula0501.o
AULA0505AOBJS = aula0505a.o aula0504.o
AULA0505BOBJS = aula0505b.o aula0504.o
AULA0506AOBJS = aula0506a.o aula0504.o
AULA0506BOBJS = aula0506b.o aula0504.o

AULA0602OBJS  = aula0602.o aula0601.o
AULA0603OBJS  = aula0603.o aula0601.o
AULA0604OBJS  = aula0604.o aula0601.o
AULA0605OBJS  = aula0605.o aula0601.o
AULA0606OBJS  = aula0606.o aula0601.o

AULA0702OBJS  = aula0702.o aula0701.o
AULA0703OBJS  = aula0703.o aula0701.o
AULA0704OBJS  = aula0704.o aula0701.o
AULA0705OBJS  = aula0705.o aula0701.o
AULA0706OBJS  = aula0706.o aula0701.o

AULA0802OBJS  = aula0802.o
AULA0803OBJS  = aula0803.o
AULA0804OBJS  = aula0804.o
AULA0805OBJS  = aula0805.o
AULA0806OBJS  = aula0806.o
AULA0807OBJS  = aula0807.o

AULA0902OBJS  = aula0902.o
AULA0903OBJS  = aula0903.o
AULA0904OBJS  = aula0904.o
AULA0905OBJS  = aula0905.o
AULA0906OBJS  = aula0906.o
AULA0907OBJS  = aula0907.o

LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o aula0403a.o
LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o aula0403b.o aula0403e.o
LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o aula0403c.o
LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o aula0403d.o
LIBMATEMATICAOBJS = aula0601.o
LIBMONITOROBJS = aula0701.o
LIBBASEOBJS = aula0801.o
LIBARQUIVOSOBJS = aula0901.o

LIBMATEMATICARECURSAO = libmatematicarecursao.a
LIBMATEMATICADOWHILE = libmatematicadowhile.a
LIBMATEMATICAFOR = libmatematicafor.a
LIBMATEMATICAWHILE = libmatematicawhile.a
LIBMATEMATICA = libmatematica.a
LIBMONITOR = libmonitor.a
LIBBASE = libbase.a
LIBARQUIVOS = libarquivos.a

AULA01  = aula0101 aula0102 aula0103
AULA02  = aula0202a aula0202b aula0202c aula0202d
AULA03  = aula0302a aula0302b aula0302c aula0302d
AULA04  = aula0402a aula0402b aula0402c aula0402d aula0404a aula0404b aula0404c aula0404d aula0404e
AULA05  = aula0502a aula0502b aula0503a aula0503b aula0505a aula0505b aula0506a aula0506b
AULA06  = aula0602 aula0603 aula0604 aula0605 aula0606
AULA07  = aula0702 aula0703 aula0704 aula0705 aula0706
AULA08  = aula0802 aula0803 aula0804 aula0805 aula0806 aula0807
AULA09  = aula0902 aula0903 aula0904 aula0905 aula0906 aula0907


EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04) $(AULA05) $(AULA06) $(AULA07) $(AULA08) $(AULA09)

LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR) $(LIBMATEMATICAWHILE) $(LIBMATEMATICA) $(LIBMONITOR) $(LIBBASE) $(LIBARQUIVOS)

ALL = $(EXECS) $(LIBS)

#regra implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula01: $(AULA01)

aula02: $(AULA02)

aula03: $(AULA03)

aula04: $(AULA04)

aula05: $(AULA05) 

aula06: $(AULA06)    

aula07: $(AULA07)

aula08: $(AULA08)

aula09: $(AULA09)


aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS) 
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)


aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)


aula0302a:  $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)


aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 

aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)  

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 

aula0404a: $(AULA0404AOBJS) $(LIBMATEMATICARECURSAO)
	$(LD) $(LFLAGS) -o $@ $(AULA0404AOBJS) -L. -lmatematicarecursao   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 

aula0404b: $(AULA0404BOBJS) $(LIBMATEMATICADOWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0404BOBJS) -L. -lmatematicadowhile   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)  

aula0404c: $(AULA0404COBJS) $(LIBMATEMATICAFOR)
	$(LD) $(LFLAGS) -o $@ $(AULA0404COBJS) -L. -lmatematicafor   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)  

aula0404d: $(AULA0404DOBJS) $(LIBMATEMATICAWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0404DOBJS) -L. -lmatematicawhile   
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)  

aula0404e: $(AULA0404EOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404EOBJS) -lm  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   


aula0502a: $(AULA0502AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502AOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   
  
aula0502b: $(AULA0502BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502BOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0503a: $(AULA0503AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503AOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   
 
aula0503b: $(AULA0503BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503BOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)  

aula0505a: $(AULA0505AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0505AOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

aula0505b: $(AULA0505BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0505BOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0506a: $(AULA0506AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0506AOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0506b: $(AULA0506BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0506BOBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

  
  
aula0602: $(AULA0602OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602OBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0603: $(AULA0603OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603OBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0604: $(AULA0604OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0604OBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0605: $(AULA0605OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605OBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   
 
aula0606: $(AULA0606OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606OBJS)  
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   


 
aula0702: $(AULA0702OBJS) $(LIBMONITOR) 
	$(LD) $(LFLAGS) -o $@ $(AULA0702OBJS) -L. -lmonitor
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0703: $(AULA0703OBJS) $(LIBMONITOR) 
	$(LD) $(LFLAGS) -o $@ $(AULA0703OBJS) -L. -lmonitor
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0704: $(AULA0704OBJS) $(LIBMONITOR) 
	$(LD) $(LFLAGS) -o $@ $(AULA0704OBJS) -L. -lmonitor 
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   

aula0705: $(AULA0705OBJS) $(LIBMONITOR) 
	$(LD) $(LFLAGS) -o $@ $(AULA0705OBJS) -L. -lmonitor 
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)   
 
aula0706: $(AULA0706OBJS) $(LIBMONITOR) 
	$(LD) $(LFLAGS) -o $@ $(AULA0706OBJS) -L. -lmonitor
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
            

aula0802: $(AULA0802OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0802OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
          
aula0803: $(AULA0803OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0803OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
          
aula0804: $(AULA0804OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0804OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
            
aula0805: $(AULA0805OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0805OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0806: $(AULA0806OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0806OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0807: $(AULA0807OBJS) $(LIBBASE) 
	$(LD) $(LFLAGS) -o $@ $(AULA0807OBJS) -L. -lbase
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  

 
aula0902: $(AULA0902OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0902OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
          
aula0903: $(AULA0903OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0903OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
          
aula0904: $(AULA0904OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0904OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO) 
            
aula0905: $(AULA0905OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0905OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0906: $(AULA0906OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0906OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)
  
aula0907: $(AULA0907OBJS) $(LIBARQUIVOS) 
	$(LD) $(LFLAGS) -o $@ $(AULA0907OBJS) -L. -larquivos
	cp $@ $@-$(OS)-$(CC)-$(DIALETO)

#aula0907: $(AULA0907OBJS) $(LIBARQUIVOS) 
#	$(LD) $(LFLAGS) -o $@ $(AULA0907OBJS) -L -l. $(LIBARQUIVOS)
#	cp $@ $@-$(OS)-$(CC)-$(DIALETO)


libmatematicarecursao.a: $(LIBMATEMATICARECURSAOOBJS)
	ar -r -c $@ $(LIBMATEMATICARECURSAOOBJS)

libmatematicadowhile.a: $(LIBMATEMATICADOWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICADOWHILEOBJS)
  
libmatematicafor.a: $(LIBMATEMATICAFOROBJS)
	ar -r -c $@ $(LIBMATEMATICAFOROBJS)
  
libmatematicawhile.a: $(LIBMATEMATICAWHILEOBJS)
	ar -r -c $@ $(LIBMATEMATICAWHILEOBJS) 

libmatematica.a: $(LIBMATEMATICAOBJS)
	ar -r -c $@ $(LIBMATEMATICAOBJS) 

libmonitor.a: $(LIBMONITOROBJS)
	ar -r -c $@ $(LIBMONITOROBJS) 
    
libbase.a: $(LIBBASEOBJS)
	ar -r -c $@ $(LIBBASEOBJS) 

libarquivos.a: $(LIBARQUIVOSOBJS)
	ar -r -c $@ $(LIBARQUIVOSOBJS) 

  
.PHONY: clean clean-all clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c89 clean-c90 clean-c99 clean-c11

clean:
	rm -f *.o $(ALL) *.core

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-* *.core

clean-objs:
	rm -f *.o *.core

clean-bsd:
	rm -f *.o $(ALL) *-FreeBSD-* *.core

clean-linux:
	rm -f *.o $(ALL) *-Linux-* *.core

clean-gcc:
	rm -f *.o $(ALL) *-gcc-* *.core

clean-clang:
	rm -f *.o $(ALL) *-clang-* *.core

clean-ansi:
	rm -f *.o $(ALL) *-ansi *.core

clean-c89:
	rm -f *.o $(ALL) *-c89 *.core

clean-c90:
	rm -f *.o $(ALL) *-c90 *.core

clean-c99:
	rm -f *.o $(ALL) *-c99 *.core

clean-c11:
	rm -f *.o $(ALL) *-c11 *.core           

#$RCSfile: GNUmakefile,v $
