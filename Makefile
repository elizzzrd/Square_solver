program: main.o input_output.o solving.o stuff.o
	gcc main.o input_output.o solving.o stuff.o -o program

main.o: main.c ss.h
	gcc -c main.c -o main.o

input_output.o: input_output.c ss.h
	gcc -c input_output.c -o input_output.o

solving.o: solving.c ss.h
	gcc -c solving.c -o solving.o

stuff.o: stuff.c ss.h
	gcc -c stuff.c -o stuff.o

clean:
	del -f *.o program
