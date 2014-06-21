all: PrintFileFlags clean
PrintFileFlags: PrintFileFlags.o  Err_functions_output.o 
	gcc -o PrintFileFlags PrintFileFlags.o  Err_functions_output.o
PrintFileFlags.o: PrintFileFlags.c
	gcc -o PrintFileFlags.o -g -c PrintFileFlags.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f PrintFileFlags.o Err_functions_output.o
