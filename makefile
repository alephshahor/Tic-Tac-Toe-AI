CC = gcc
CXX = g++
RM = rm -f
FLAGS = -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -o


TicTacToe: main.o tieScreen.o crossWinScreen.o circleWinScreen.o gameScreen.o firstScreen.o turn.o field.o cell.o
	$(CXX) main.o tieScreen.o crossWinScreen.o circleWinScreen.o gameScreen.o firstScreen.o field.o turn.o cell.o $(FLAGS) TicTacToe

main.o: main.cpp

tieScreen.o: tieScreen.hpp tieScreen.cpp

crossWinScreen.o: crossWinScreen.hpp crossWinScreen.cpp

circleWinScreen.o: circleWinScreen.hpp circleWinScreen.cpp

gameScreen.o: gameScreen.hpp gameScreen.cpp

firstScreen.o: firstScreen.hpp firstScreen.cpp

turn.o: turn.hpp turn.cpp

field.o: field.hpp field.cpp

cell.o: cell.hpp cell.cpp

clean:
	$(RM) TicTacToe main.o tieScreen.o crossWinScreen.o circleWinScreen.o gameScreen.o firstScreen.o turn.o field.o cell.o
