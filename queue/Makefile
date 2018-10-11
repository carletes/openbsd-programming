.SUFFIXES: .c .o

.c.o:
	${CC} -O2 -pipe -Wall -Werror -c $<

all: slist

slist: slist.o
	${CC} ${CFLAGS} -o $@ slist.o
