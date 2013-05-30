# tetris

tetris: main.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o
	g++ -o bin/tetris main.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o -lncursesw

tetris_simple: main_simple.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o
	g++ -o bin/tetris_simple main_simple.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o

main.o: ncurses_interface/main.cpp
	g++ -c ncurses_interface/main.cpp

main_simple.o: simple_interface/main.cpp
	g++ -o main_simple.o -c simple_interface/main.cpp

block.o: modules/block.cpp
	g++ -c modules/block.cpp

field.o: modules/field.cpp
	g++ -c modules/field.cpp

source.o: source/source.cpp
	g++ -c source/source.cpp

square.o: modules/square.cpp
	g++ -c modules/square.cpp

line.o: modules/line.cpp
	g++ -c modules/line.cpp

stairleft.o: modules/stairleft.cpp
	g++ -c modules/stairleft.cpp

stairright.o: modules/stairright.cpp
	g++ -c modules/stairright.cpp

pedestal.o: modules/pedestal.cpp
	g++ -c modules/pedestal.cpp

cornerleft.o: modules/cornerleft.cpp
	g++ -c modules/cornerleft.cpp

cornerright.o: modules/cornerright.cpp
	g++ -c modules/cornerright.cpp

testfigure.o: modules/testfigure.cpp
	g++ -c modules/testfigure.cpp

clean:
	rm -f *.o tetris
