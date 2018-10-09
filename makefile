CC = gcc
CXX = g++
RM = rm -f
FLAGS = -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -o


TicTacToe: main.o field.o cell.o
	$(CXX) main.o field.o cell.o $(FLAGS) TicTacToe

main.o: main.cpp

field.o: field.hpp field.cpp

cell.o: cell.hpp cell.cpp

clean:
	$(RM) TicTacToe main.o field.o cell.o common.o
