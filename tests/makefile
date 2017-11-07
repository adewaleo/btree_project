# Btree Tests Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -NDEBUG  -O -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

BUILDIR = ../build
LIBRARYDIR = ../libraries
APPSDIR = ../applications

OBJECTFILES = $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o \
	$(BUILDIR)/relapps.o
EXECFILE = $(BUILDIR)/rangequery

# dependency rules for nonfile targets 
all: fetchdeps $(EXECFILE) clean

fetchdeps:
	cp $(LIBRARYDIR)/relation.h . 
	cp $(LIBRARYDIR)/util.h .
	cp $(APPSDIR)/relapps.h .

	cp $(BUILDIR)/*.o .

cleandeps:
	rm -f relation.h
	rm -f util.h
	rm -f relapps.h

clean: cleandeps
	rm -f *.o

$(EXECFILE): rangequeryclient.o $(OBJECTFILES)
	$(MAKE) -C $(LIBRARYDIR)
	$(MAKE) -C $(APPSDIR)
	$(CC) $(CFLAGS) rangequeryclient.o $(OBJECTFILES) -o $@

rangequeryclient.o: rangequeryclient.c relation.h util.h relapps.h
	$(CC) $(CFLAGS) -c $<

