all: testStdInput  clean
testStdInput: testStdInput.o  Err_functions_output.o 
	gcc -o testStdInput testStdInput.o  Err_functions_output.o
testStdInput.o: testStdInput.c
	gcc -o testStdInput.o -g -c testStdInput.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f testStdInput.o Err_functions_output.o
