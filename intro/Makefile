include ../Make.defines

PROGS = daytimetcpcli daytimetcpser

all : ${PROGS}

daytimetcpcli:	daytimetcpcli.o
		${CC} ${CFLAGS} -o $@ daytimetcpcli.o ${LIBS}

daytimetcpser:	daytimetcpser.o
		${CC} ${CFLAGS} -o $@ daytimetcpser.o ${LIBS}

clean:
		rm -f ${PROGS}