# Btree Libraries Makefile
# Author: Oluwatosin V. Adewale

CC = gcc 

# Normal build
# CFLAGS = -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

# Debug Build (note: .o files needed when debugging in netbeans)
 CFLAGS = -g -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

# Optimized build
# CFLAGS = -D NDEBUG  -O3 -Wall -Wextra -Wno-unused-parameter -pedantic -Wall -std=c89

# Library object files
UTILOBJ = util.o
RELATIONOBJ = relation_mem.o
STRINGBAGOBJ = stringbag.o
RELAPPSOBJ = relapps.o
BORDERNODEOBJ = bordernode.o
KVSTOREOBJ = kvstore.o

LIBOBJECTFILES =    $(UTILOBJ) $(RELATIONOBJ) $(STRINGBAGOBJ) $(RELAPPSOBJ) \
		    $(BORDERNODEOBJ) $(KVSTOREOBJ)

# Test object Files
RANGECLIENTOBJ = rangequeryclient.o 
RELATIONTESTSOBJ = relationtests.o 
STRINGBAGCLIENTOBJ = stringbagclient.o
KVSTORETESTSOBJ = kvstoretests.o
TESTOBJFILES =	    $(RANGECLIENTOBJ) $(RELATIONTESTSOBJ) $(STRINGBAGCLIENTOBJ) \
		    $(KVSTORETESTSOBJ)

# Executable Files
RANGEEXEC = rangequery.exe
RELATIONTESTSEXEC = relationtests.exe
STRINGBAGCLIENT = stringbagclient.exe
KVSTORETESTS = kvstoretests.exe
TESTEXECFILES = $(RANGEEXEC) $(RELATIONTESTSEXEC) $(STRINGBAGCLIENT) \
		$(KVSTORETESTS)

all: $(LIBOBJECTFILES) $(TESTOBJFILES) $(TESTEXECFILES)

clean:
	rm -f *.o
	
# Rules to build executable targets.
$(RANGEEXEC): rangequeryclient.o util.o relation_mem.o relapps.o
	$(CC) $(CFLAGS) rangequeryclient.o util.o relation_mem.o relapps.o -o $@
	
$(RELATIONTESTSEXEC): relationtests.o util.o relation_mem.o bordernode.o
	$(CC) $(CFLAGS) relationtests.o util.o relation_mem.o bordernode.o -o $@
	
$(STRINGBAGCLIENT): stringbagclient.o util.o stringbag.o
	$(CC) $(CFLAGS) stringbagclient.o util.o stringbag.o -o $@

$(KVSTORETESTS): kvstoretests.o kvstore.o util.o bordernode.o relation_mem.o
	$(CC) $(CFLAGS) kvstoretests.o kvstore.o util.o \
			bordernode.o relation_mem.o -o $@


# Rules to build client / test object file targets.
rangequeryclient.o: rangequeryclient.c relation.h util.h relapps.h
	$(CC) $(CFLAGS) -c $<
	
relationtests.o: relationtests.c relation.h util.h
	$(CC) $(CFLAGS) -c $<

stringbagclient.o: stringbagclient.c  stringbag.h util.h
	$(CC) $(CFLAGS) -c $<

kvstoretests.o: kvstoretests.c relation.h util.h bordernode.h kvstore.h
	$(CC) $(CFLAGS) -c $<


# Rules to build implementation / library object file targets.
relapps.o: relapps.c relapps.h relation.h util.h
	$(CC) $(CFLAGS) -c $<
	
util.o: util.c util.h
	$(CC) $(CFLAGS) -c $<

relation_mem.o: relation_mem.c relation.h util.h 
	$(CC) $(CFLAGS) -c $<
	
stringbag.o: stringbag.c stringbag.h util.h
	$(CC) $(CFLAGS) -c $<
	
bordernode.o: bordernode.c bordernode.h relation.h util.h
	$(CC) $(CFLAGS) -c $<

kvstore.o: kvstore.c kvstore.h bordernode.h relation.h util.h
	$(CC) $(CFLAGS) -c $<
