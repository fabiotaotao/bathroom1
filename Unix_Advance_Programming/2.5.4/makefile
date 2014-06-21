all: configlimits  clean
configlimits: configlimits.o  Err_functions_output.o 
	gcc -o configlimits configlimits.o  Err_functions_output.o
configlimits.o: configlimits.c
	gcc -o configlimits.o -g -c configlimits.c
Err_functions_output.o:../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f configlimits.o Err_functions_output.o
