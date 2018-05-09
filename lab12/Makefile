# Daniel Bravo
# 2018-05-16
# CPSC 223C-01/02
# Lab 12

# Use this for Linux complier
CC=gcc

# Use this for Mac compiler
# CC=/usr/local/bin/gcc-7

INCLUDES= `pkg-config --cflags gobject-2.0`
LIBS = `pkg-config --libs gobject-2.0`

CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES)

PROG = main
SRCS = main.c person.c student.c
OBJS = $(SRCS:.c=.o)

test: $(PROG)
	./$(PROG)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LIBS)

main.o: main.c

person.o: person.c

student.o: student.c

clean:
	rm -f core $(PROGS) $(OBJS)
