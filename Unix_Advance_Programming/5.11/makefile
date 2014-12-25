all: pr_stdio  clean
pr_stdio: pr_stdio.o  Err_functions_output.o 
	gcc -o  pr_stdio pr_stdio.o  Err_functions_output.o
pr_stdio.o: pr_stdio.c
	gcc -o pr_stdio.o -g -c pr_stdio.c
Err_functions_output.o:../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f pr_stdio.o Err_functions_output.o
