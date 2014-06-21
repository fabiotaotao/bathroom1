all:ReadCommandsAndExecute clean
ReadCommandsAndExecute:ReadCommandsAndExecute.o Err_functions_output.o 
	gcc -o ReadCommandsAndExecute ReadCommandsAndExecute.o  Err_functions_output.o
ReadCommandsAndExecute.o: ReadCommandsAndExecute.c
	gcc -o ReadCommandsAndExecute.o -g -c ReadCommandsAndExecute.c
Err_functions_output.o:../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f ReadCommandsAndExecute.o Err_functions_output.o
