CXX=g++
XXFLAGS=-Wall -MMD
EXEC=main
OBJECTS=main.o tile.o plant.o grid.o randmath.o vector.o genepack.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${XXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}
