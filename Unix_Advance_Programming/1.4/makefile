all:testlistfile clean
testlistfile:testlistfile.o Err_functions_output.o 
	gcc -o testlistfile testlistfile.o  Err_functions_output.o
testlistfile.o: testListFile.c
	gcc -o testlistfile.o -g -c testListFile.c
Err_functions_output.o:Error_functions_output.c
	gcc -o Err_functions_output.o -g -c Error_functions_output.c
.PHONY:clean
clean:
	rm -f testlistfile.o Err_functions_output.o
