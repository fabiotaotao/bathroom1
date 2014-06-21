all: PrintFileType clean
PrintFileType:  PrintFileType.o  Err_functions_output.o 
	gcc -o PrintFileType PrintFileType.o  Err_functions_output.o
PrintFileType.o: PrintFileType.c
	gcc -o PrintFileType.o -g -c PrintFileType.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f PrintFileType.o Err_functions_output.o
