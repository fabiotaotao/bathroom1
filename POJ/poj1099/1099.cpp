#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

vector<string> ICE;
vector<vector<int> > ASM;


void PRINT()
{
	for(vector<string>::iterator it=ICE.begin();it!=ICE.end();it++) 
		cout<<*it<<endl;

}



int main(void)
{
	int n=0;
	int m=0;
	cin>>n>>m;
	cout<<"n="<<n<<"; m="<<m<<endl;


	for (int i=0;i<n;i++)
	{
		vector<int> line;
		for(int j=0;j<n;j++)
		{
			int value;
			cin>>value;
			line.push_back(value);
			if(line.size()==n)
				ASM.push_back(line);

		}
		
			
	}
	for (int i=0;i<n;i++)
	{
		cout<<endl;
		for (int j=0;j<n;j++)
			cout<<ASM[i][j]<<" ";



	}
	cout<<endl;
	string s;//=string(3*n+1,' ');
	for (int i=0;i<4*n-3;i++)
	{
		s=string(4*n+1,' ');
		if(i%4==0)
		{
			for (int j=0;j<4*n+1;j+=2)
				{	
					if(j%4==2)	
					{
						s.at(j)='O';
						
					}
					else if(j%4==0)
						s.at(j)='H';
					
						
				}
		}

		if(i%4==2)
		{
			for(int j=0;j<4*n+1;j++)
				if(j%4==2)
					s.at(j)='H';		
		}
		ICE.push_back(s);

	}
	
	for(int i=0;i<4*n-3;i+=4)
	{
		if(i%4==0)
		{
			for(int j=2;j<4*n+1;j+=4)
			{	
				if(ASM[i/4][j/4]==1)	
				{
					ICE[i].at(j-1)='-';
					ICE[i].at(j+1)='-';
				}
				else if(ASM[i/4][j/4]==-1)
				{
					ICE[i-1].at(j)='|';
					ICE[i+1].at(j)='|';
				}
				else if(ASM[i/4][j/4]==0)
				{
					if(j==4*n-2)
					{
						ICE[i].at(j+1)='-';
						if(i==0)
						ICE[i+1].at(j)='|';
						else if(i==4*n-4)
						ICE[i-1].at(j)='|';
					}

					if(j==2)
					{	
						ICE[i].at(j-1)='-';
						if(i==0)
						ICE[i+1].at(j)='|';
						else if(i==4*n-4)
						ICE[i-1].at(j)='|';
						else if (ICE[i-3].at(j)!='|') 
						ICE[i-1].at(j)='|';
						else
						ICE[i-1].at(j)=' ';
						
					}
					else if(ICE[i].at(j-3)!='-')
					{ 
						ICE[i].at(j-1)='-';
						ICE[i].at(j+1)=' ';
						if(i==0)
							ICE[i+1].at(j)='|';
						else if (ICE[i-3].at(j)!='|')
							ICE[i-1].at(j)='|';
						else
							ICE[i+1].at(j)='|';
					}
					else
					{
						ICE[i].at(j-1)=' ';
						ICE[i].at(j+1)='-';
						if(i==0)
							ICE[i+1].at(j)='|';
						else if (ICE[i-3].at(j)!='|')
							ICE[i-1].at(j)='|';
						else
							ICE[i+1].at(j)='|';

					}	
				}	
			}
		}
	}



	PRINT();


//	string s(10,' ');
//	s.at(6)='a';
//	cout<<s<<endl;




//	printf("%s\n",s.c_str());
	return 0;	


}














