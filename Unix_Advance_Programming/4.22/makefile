all: DescendDirectory clean
DescendDirectory:  DescendDirectory.o  Err_functions_output.o  AllocatePathname.o
	gcc -o DescendDirectory DescendDirectory.o  Err_functions_output.o AllocatePathname.o
DescendDirectory.o: DescendDirectory.c
	gcc -o DescendDirectory.o -g -c DescendDirectory.c
AllocatePathname.o: AllocatePathname.c
	gcc -o AllocatePathname.o -g -c AllocatePathname.c 
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f DescendDirectory.o Err_functions_output.o AllocatePathname.o
