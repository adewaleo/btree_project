# Btree Applications Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -NDEBUG  -O -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

BUILDIR = ../build
LIBRARYDIR = ../libraries

OBJECTFILES = $(BUILDIR)/relapps.o

# dependency rules for nonfile targets 
all:  $(OBJECTFILES) clean

clean: 
	rm -f *.o

$(BUILDIR)/relapps.o: relapps.c relapps.h $(LIBRARYDIR)/relation.h $(LIBRARYDIR)/util.h
	$(CC) $(CFLAGS) -c $<
	mv relapps.o $(BUILDIR)
