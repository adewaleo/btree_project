# Btree Applications Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
 # CFLAGS = -NDEBUG  -O -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

BUILDIR = ../build
LIBRARYDIR = ../libraries

OBJECTFILES = $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o
EXECFILE = $(BUILDIR)/range_query

# dependency rules for nonfile targets 
all: $(EXECFILE)

clean:
	rm -f *.o

$(EXECFILE): range_query.o $(OBJECTFILES)
	$(MAKE) -C $(LIBRARYDIR)
	$(CC) $(CFLAGS) range_query.o $(OBJECTFILES) -o $@

range_query.o: range_query.c $(LIBRARYDIR)/relation.h $(LIBRARYDIR)/util.h
	cp $(LIBRARYDIR)/relation.h . 
	cp $(LIBRARYDIR)/util.h .
	$(CC) $(CFLAGS) -c $<
	rm -f relation.h
	rm -f util.h









