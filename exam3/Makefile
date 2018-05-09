# Daniel Bravo
# 2018-04-18
# CPSC 223C-01/02
# Exam 3

# Use this for Linux complier
CC=gcc

# Use this for Mac compiler
#CC=/usr/local/bin/gcc-7

#INCLUDES=-!$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option -D_POSIX_C_SOURCE=200801L $(INCLUDES)

PROG = exam3
SRCS = main.c filter.c
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o : main.c

filter.o : filter.c

clean :
	rm -f core $(PROG) $(OBJS)
