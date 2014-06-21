all: OpenAFileAndUnlink clean
OpenAFileAndUnlink:  OpenAFileAndUnlink.o  Err_functions_output.o 
	gcc -o OpenAFileAndUnlink OpenAFileAndUnlink.o  Err_functions_output.o
OpenAFileAndUnlink.o: OpenAFileAndUnlink.c
	gcc -o OpenAFileAndUnlink.o -g -c OpenAFileAndUnlink.c
Err_functions_output.o: ../Error_functions_output.c
	gcc -o Err_functions_output.o -g -c ../Error_functions_output.c
.PHONY:clean
clean:
	rm -f OpenAFileAndUnlink.o Err_functions_output.o
