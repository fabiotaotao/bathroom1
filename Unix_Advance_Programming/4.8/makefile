all: accessfunc clean
accessfunc:  accessfunc.o  Err_functions_output.o 
	gcc -o accessfunc accessfunc.o  Err_functions_output.o
accessfunc.o: accessfunc.c
	gcc -o accessfunc.o -g -c accessfunc.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f accessfunc.o Err_functions_output.o
