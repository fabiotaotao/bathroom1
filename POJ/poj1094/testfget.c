#include <stdio.h>
#include <string.h>

void fun(int ** mat)
{
 printf(mat[0][0]);
}


int main()
{
	char word[3];
	int n,m;
	scanf("%d %d",&n,&m);
//	while(scanf("%s",word))
//	{
//		printf("%s\n",word);
//	}

	int matrix[3][3];
	int i,j=0;
	for (i=0;i<3;i++)
		for(j=0;j<3;j++)
			matrix[i][j]=0;

	fun(matrix);

	return 0;
}
