# Exam 2 - Makefile
#
# Use of this Makefile is OPTIONAL.
# You do not need this unless you want to use The Better String Library.
#
# If you do want to use The Better String Library, start with the repository
# from GitHub and save this file and exam2.c in these locations:
#   cpsc223c/exam2/Makefile
#   cpsc223c/exam2/exam2.c
#
# For details of how to clone the repository and submodules correctly, see the
# README.md from this URL:
#   https://github.com/ProfAvery/cpsc223c
#

CC=gcc
INCLUDES=-I$(DEBUGDIR) -I$(BSTRDIR)
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option $(INCLUDES) -DWANT_BSTRLIB

PROG = exam2
SRCS = exam2.c
OBJS = $(SRCS:.c=.o)

BSTRDIR = ../bstrlib
BSTRSRCS = $(BSTRDIR)/bstrlib.c $(BSTRDIR)/bstraux.c
BSTROBJS = $(BSTRSRCS:.c=.o)
BSTRFLAGS = -O3 -Wall -pedantic -ansi -s

DEBUGDIR = ../debug

all: $(PROG)

exam2: $(OBJS) $(BSTROBJS)
	$(CC) $(OBJS) $(BSTROBJS) -o $(PROG)

exam2.o: exam2.c

$(BSTRDIR)/%.o: $(BSTRDIR)/%.c $(BSTRDIR)/%.h
	$(CC) $(BSTRFLAGS) -c $< -o $@

clean:
	rm -f core $(PROG) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)

