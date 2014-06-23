#include <stdio.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

static int sum=0;
static string orderstring;

string sortMatrix(int n, int result[26][26])
{
	string  sortedletters;
	map<int, char> sortmap;
	int rank;
	for(int j=0;j<n;j++)
	{
		rank=0;
		for (int i=0;i<n;i++)
			rank+=result[i][j];
	
		sortmap[rank]=(char)(j+65);
	}	

	for(map<int, char>::iterator it=sortmap.begin(); it!=sortmap.end() ;it++)
		sortedletters.push_back(it->second);

	return sortedletters;
}





int setMatrix(int n,char *str,int result[26][26])
{
	int oldvalue;
	int checkrow=(int)str[0]-65;
	int checkcol=(int)str[2]-65;
	if(result[checkcol][checkrow]==1)
		return -1;
	oldvalue=result[checkrow][checkcol];
	if(oldvalue==0)	
		sum++;
	result[checkrow][checkcol]=1;

	for(int i=0;i<n;i++)
	{
		if(i!=checkcol && i!=checkrow)
			{
			oldvalue=result[i][checkcol];

			if(oldvalue==0 && result[i][checkrow] == 1)
				{
			        result[i][checkcol]=1;
				sum++;
				}
			oldvalue=result[checkrow][i];

			if(oldvalue==0 && result[checkcol][i] == 1)
				{
				result[checkrow][i]=1;
				sum++;
				}
			}
	}
	
//	printf("sum= %d\n",sum);
	if(sum< (n*n-n)/2)
		return 1;
	else if(sum==(n*n-n)/2)
		return 0;
	else if(sum>(n*n-n)/2)
		return -1;
}




int main(void)
{
	char buf[4];
	int n,m;
	scanf("%d %d",&n,&m);

	int complete=0;
	sum=0;
	if(m<n-1)
	{
		printf("Sorted sequence cannot be determined\n");
		return 0;
	}
	int  matrixResult [26][26];
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++)
		matrixResult[i][j]=0;
	}

	
	for (int i=0;i<m;i++)
	{
		scanf("%s",buf);
		int aftersetMatrix=setMatrix(n,buf,matrixResult);
		if(0==aftersetMatrix && complete==0)
			{	
				complete=i+1;
			}		
		if(-1==aftersetMatrix)
			{
				printf("Inconsistency found after %d relations.\n",i+1);	
				return 0;	
			}
	}
//	printf("%d,%d",sum,complete);
	if(complete!=-1&&complete!=0)
		{
		
		printf("Sorted sequence determined after %d relations: %s.\n",complete,sortMatrix(n,matrixResult).c_str());
		}	
	else if(complete==0)
		printf("Sorted sequence cannot be determined.\n");
//	printf("%d\n",'A');
	return 0;


}
