# based on http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# Sat Apr 14 11:01:20 CDT 2012

CC=gcc 
SRC=Hawley-hw11.c
BINLIB=hw11-lib.c
DEPS=hw11-lib.h

# type 
#   make
# to build
a.out: ${SRC} ${BINLIB} ${DEPS}
	${CC} -std=c89 -pedantic ${SRC} ${BINLIB}


# type 
#   make clean
# to remove a.out
clean:
	rm a.out
