# Daniel Bravo
# 2018-04-04
# CPSC 223C-01/02
# Lab 7

CC=gcc
#CC=/usr/local/bin/gcc-7
#INCLUDES=-!$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

PROG = phonebook
SRCS = main.c commands.c faculty.c
OBJS = $(SRCS: .c=.o)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o : main.c

commands.o : commands.c

faculty.o : faculty.c


clean :
	rm -f core $(PROG) $(OBJS)

