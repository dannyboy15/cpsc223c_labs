# Daniel Bravo
# 2018-04-11
# CPSC 223C-01/02
# Lab 8

# Use this for Linux complier
#CC=gcc

# Use this for Mac compiler
CC=/usr/local/bin/gcc-7

INCLUDES=-I$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option -D_POSIX_C_SOURCE=200801L $(INCLUDES)

PROG = calculator
SRCS = main.c commands.c operations.c
OBJS = $(SRCS:.c=.o)

BSTRDIR = ../bstrlib
BSTRSRCS = $(BSTRDIR)/bstrlib.c $(BSTRDIR)/bstraux.c
BSTROBJS = $(BSTRSRCS:.c=.o)
BSTRFLAGS = -O3 -Wall -pedantic -ansi -s

DEBUGDIR = ../debug

$(PROG) : $(OBJS) $(BSTROBJS)
	$(CC) $(OBJS) $(BSTROBJS) -o $(PROG)

main.o : main.c

commands.o : commands.c

operations.o : operations.c

$(BSTRDIR)/%.o: $(BSTRDIR)/%.c $(BSTRDIR)/%.h
	$(CC) $(BSTRFLAGS) -c $< -o $@

clean :
	rm -f core $(PROG) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)
