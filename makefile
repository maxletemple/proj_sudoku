sudoku_v2: sudoku_v2.o sudoku.o
	gcc -o sudoku_v2 sudoku_v2.o sudoku.o

main: main.o sudoku.o
	gcc -o main main.o sudoku.o

sudoku_v1: sudoku_v1.o sudoku.o
	gcc -o sudoku_v1 sudoku_v1.o sudoku.o

main.o: main.c sudoku.h
	gcc -c main.c -Wall

sudoku.o: sudoku.c sudoku.h
	gcc -c sudoku.c -Wall

sudoku_v1.o: sudoku_v1.c sudoku.h
	gcc -c sudoku_v1.c -Wall

sudoku_v2.o: sudoku_v2.c sudoku.h
	gcc -c sudoku_v2.c -Wall

clean:
	rm *.o