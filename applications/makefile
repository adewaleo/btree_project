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
all: fetchdeps $(OBJECTFILES) clean

fetchdeps:
	cp $(LIBRARYDIR)/relation.h . 
	cp $(LIBRARYDIR)/util.h .

clean: cleandeps
	rm -f *.o

cleandeps:
	rm -f relation.h
	rm -f util.h

$(BUILDIR)/relapps.o: relapps.c relapps.h relation.h util.h
	$(CC) $(CFLAGS) -c $<
	mv relapps.o $(BUILDIR)
