all: chmodfunc clean
chmodfunc:  chmodfunc.o  Err_functions_output.o 
	gcc -o chmodfunc chmodfunc.o  Err_functions_output.o
chmodfunc.o: chmodfunc.c
	gcc -o chmodfunc.o -g -c chmodfunc.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f chmodfunc.o Err_functions_output.o
