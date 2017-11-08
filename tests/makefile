# Btree Tests Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
# CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
# CFLAGS = -NDEBUG  -O -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

BUILDIR = ../build
LIBRARYDIR = ../libraries
APPSDIR = ../applications

OBJECTFILES = $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o $(BUILDIR)/relapps.o
RANGEEXEC = $(BUILDIR)/rangequery
RELATIONTESTSEXEC = $(BUILDIR)/relationtests

# dependency rules for nonfile targets 
all:  builddeps $(RANGEEXEC) $(RELATIONTESTSEXEC) clean

builddeps:
	$(MAKE) -C $(LIBRARYDIR)
	$(MAKE) -C $(APPSDIR)

clean: 
	rm -f *.o

$(RANGEEXEC): rangequeryclient.o $(OBJECTFILES)
	$(CC) $(CFLAGS) rangequeryclient.o $(OBJECTFILES) -o $@
	cp $(RANGEEXEC) .
	
$(RELATIONTESTSEXEC): relationtests.o $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o
	$(CC) $(CFLAGS) relationtests.o $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o -o $@
	cp $(RELATIONTESTSEXEC) .

rangequeryclient.o: rangequeryclient.c $(LIBRARYDIR)/relation.h $(LIBRARYDIR)/util.h $(APPSDIR)/relapps.h
	$(CC) $(CFLAGS) -c $<
	
relationtests.o: relationtests.c $(LIBRARYDIR)/relation.h $(LIBRARYDIR)/util.h
	$(CC) $(CFLAGS) -c $<


