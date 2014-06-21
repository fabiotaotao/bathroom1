all: AllocatePathname clean
AllocatePathname: AllocatePathname.o  Err_functions_output.o 
	gcc -o AllocatePathname AllocatePathname.o  Err_functions_output.o
AllocatePathname.o: AllocatePathname.c
	gcc -o AllocatePathname.o -g -c AllocatePathname.c
Err_functions_output.o:../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f AllocatePathname.o Err_functions_output.o
