include ../Make.defines

all : ${LIBUNP_NAME}

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

${LIBUNP_NAME} : ${OBJECTS}
	${RM} ${LIBUNP_NAME}
	${AR} rs ${LIBUNP_NAME} *.o

clearn : 
	${RM} *.o ${LIBUNP_NAME}