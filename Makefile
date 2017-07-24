CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror -MMD
OBJECTS=main.o display.o floor.o thing.o player.o shade.o drow.o vampire.o troll.o goblin.o enemy.o human.o dwarf.o elf.o orcs.o merchant.o dragon.o halfling.o gold.o potion.o cell.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o main
.PHONY: clean
