# Daniel Bravo
# 2018-04-24
# CPSC 223C-01/02
# Lab 9

# Use this for Linux complier
# CC=gcc

# Use this for Mac compiler
CC=/usr/local/bin/gcc-7

#INCLUDES=-!$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

MKPHONEPROG = mkphone
MKPHONESRCS = mkphone.c commands.c faculty.c
MKPHONEOBJS = $(MKPHONESRCS:.c=.o)

LSPHONEPROG = lsphone
LSPHONESRCS = lsphone.c commands.c faculty.c
LSPHONEOBJS = $(LSPHONESRCS:.c=.o)

PHONEPROG = phone
PHONESRCS = phone.c commands.c faculty.c
PHONEOBJS = $(PHONESRCS:.c=.o)

PROGS = $(MKPHONEPROG) $(LSPHONEPROG) $(PHONEPROG)
SRCS = $(MKPHONESRCS) $(LSPHONESRCS) $(PHONESRCS)
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

all: $(PROGS)

mkphone: $(MKPHONEOBJS)
	$(CC) $(MKPHONEOBJS) -o $(MKPHONEPROG)

lsphone: $(LSPHONEOBJS)
	$(CC) $(LSPHONEOBJS) -o $(LSPHONEPROG)

phone: $(PHONEOBJS)
	$(CC) $(PHONEOBJS) -o $(PHONEPROG)

mkphone.o: mkphone.c

lsphone.o: lsphone.c

phone.o: phone.c

commands.o : commands.c

faculty.o : faculty.c


clean :
	rm -f core $(PROG) $(OBJS)

clean_all:
	rm -f core $(PROG) $(OBJS) *.bin
