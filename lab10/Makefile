# Daniel Bravo
# 2018-05-02
# CPSC 223C-01/02
# Lab 10

# Use this for Linux complier
CC=gcc

# Use this for Mac compiler
# CC=/usr/local/bin/gcc-7

INCLUDES= `pkg-config --cflags glib-2.0`
LIBS = `pkg-config --libs glib-2.0`
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

PROG = freq
SRCS = main.c
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LIBS)

main.o : main.c

clean :
	rm -f core $(PROGS) $(OBJS)
