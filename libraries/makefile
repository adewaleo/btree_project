# Btree Libraries Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
# CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89
# CFLAGS = -NDEBUG  -O -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

BUILDIR = ../build/
OBJECTFILES = $(BUILDIR)/util.o $(BUILDIR)/relation_mem.o

# dependency rules for nonfile targets 
all: $(OBJECTFILES)

clean:
	rm -f *.o

$(BUILDIR)/util.o: util.c util.h
	$(CC) $(CFLAGS) -c $<
	mv util.o $(BUILDIR)

$(BUILDIR)/relation_mem.o: relation_mem.c relation.h util.h 
	$(CC) $(CFLAGS) -c $<
	mv relation_mem.o $(BUILDIR)
