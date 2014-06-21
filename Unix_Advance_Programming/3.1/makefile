all: lseekfunc  clean
lseekfunc: lseekfunc.o  Err_functions_output.o 
	gcc -o lseekfunc lseekfunc.o  Err_functions_output.o
lseekfunc.o: lseekfunc.c
	gcc -o lseekfunc.o -g -c lseekfunc.c
Err_functions_output.o:../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f lseekfunc.o Err_functions_output.o
