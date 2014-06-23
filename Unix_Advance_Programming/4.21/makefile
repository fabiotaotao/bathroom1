all: utimeExample clean
utimeExample:  utimeExample.o  Err_functions_output.o 
	gcc -o utimeExample utimeExample.o  Err_functions_output.o
utimeExample.o: utimeExample.c
	gcc -o utimeExample.o -g -c utimeExample.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f utimeExample.o Err_functions_output.o
