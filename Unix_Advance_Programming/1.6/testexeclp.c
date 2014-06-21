#include <unistd.h>
int main(void)
{
	char* a="ls";
	printf("%d",(int)strlen(a));
//	execlp("ls","ls",(char *)0);
//	printf("error happens\n");
	exit(0);
}
