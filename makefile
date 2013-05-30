# tetris

tetris: main.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o

	g++ -o bin/tetris main.o block.o field.o source.o square.o line.o stairleft.o stairright.o pedestal.o cornerleft.o cornerright.o testfigure.o -lncursesw

main.o: ncurses_interface/main.cpp
	g++ -c ncurses_interface/main.cpp

block.o: block.cpp
	g++ -c block.cpp

field.o: field.cpp
	g++ -c field.cpp

source.o: source.cpp
	g++ -c source.cpp

square.o: square.cpp
	g++ -c square.cpp

line.o: line.cpp
	g++ -c line.cpp

stairleft.o: stairleft.cpp
	g++ -c stairleft.cpp

stairright.o: stairright.cpp
	g++ -c stairright.cpp

pedestal.o: pedestal.cpp
	g++ -c pedestal.cpp

cornerleft.o: cornerleft.cpp
	g++ -c cornerleft.cpp

cornerright.o: cornerright.cpp
	g++ -c cornerright.cpp

testfigure.o: testfigure.cpp
	g++ -c testfigure.cpp

clean:
	rm -f *.o tetris
