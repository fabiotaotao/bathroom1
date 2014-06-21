all: CreateFileHole  clean
CreateFileHole: CreateFileHole.o  Err_functions_output.o 
	gcc -o CreateFileHole CreateFileHole.o  Err_functions_output.o
CreateFileHole.o: CreateFileHole.c
	gcc -o CreateFileHole.o -g -c CreateFileHole.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f CreateFileHole.o Err_functions_output.o
