#include <stdio.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cmath>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;


double nmap[30][30];
double shortestdist[30][30];
int lastStop[30][30];
//int firstStop[30][30];

class Node
{
	public:
	int label;
	bool visit;
	vector<Node* > Neighbors;
	Node(const int &j,const bool& sign);
};


Node::Node(const int &j=0,const bool& sign=false):label(j),visit(sign)
{}




class Graph
{
	private:
	int VertexAmount;
	public:
	void setShortestPath();
	map<int, Node> vertice;
	map<int, map<int,double> >Edges;
	map<int, map<int,double> >Distances;
	Graph(double edges[30][30],const int &n);
	void Dijkstra(const int &i);
	int path[30][30];
	int FindNearest(const int &i,const map<int,Node> &V);	
	int Traverse(const int &i);
};

int Graph::FindNearest(const int &i,const map<int,Node> &V)
{
	int min;
	double D=-1;
/*	for(int j=0;j<VertexAmount;j++)
	{
		if(i!=j && V.find(vertice[j])!=V.end())
		{
			Distances[i][j]=	
		}
	}
*/
	for(map<int,Node>::const_iterator it=V.begin(); it!=V.end();it++)
	{
		if(D<0)
			{
				min=it->first;
				D=Distances[i][it->first];
			}
		else if(Distances[i][it->first]>=0 && D>=Distances[i][it->first])
		{
			D=Distances[i][it->first];
			min=it->first;	
		}		
	}
	if(D<0)
		return -1;
	else
		return min;
}






Graph::Graph(double edges[30][30],const int &n):VertexAmount(n)
{
	for (int i=0;i<n;i++)
	{
		vertice[i]=Node(i,false);
	}
	
	for (int i=0;i<n;i++)
	{	
		Edges[i]=map<int,double>(); 
		for(int j=0;j<n;j++)
		{
			if(j!=i && (edges[i][j]>0))
				vertice[i].Neighbors.push_back(&vertice[j]);	
			Edges[i][j]=edges[i][j];
			path[i][j]=-1;	
		}
	}
	Distances=Edges;

}

int Graph::Traverse(const int &i)
{
	int count=0;
	deque<Node> sequence;
	sequence.push_back(vertice[i]);
	vertice[i].visit=true;
	count++;
	while(!sequence.empty())
	{	
		deque<Node>::iterator it=sequence.begin();
		for(int j=0;j<it->Neighbors.size();j++) 
			{
			if(!(it->Neighbors[j]->visit))
				{
					it->Neighbors[j]->visit=true;
					sequence.push_back(*(it->Neighbors[j]));

					count++;
				}
			}
		sequence.pop_front();
	}
	for (int i=0;i<VertexAmount;i++)
		vertice[i].visit=false;
	return count;	
}
void Graph::setShortestPath()
{
	for (int i=0;i<VertexAmount;i++)
		Dijkstra(i);
}


void Graph::Dijkstra(const int &i)
{
	map <int, Node> V(vertice);
	V.erase(i);
	int closest;

	for(vector<Node* >::const_iterator it=vertice[i].Neighbors.begin();it!=vertice[i].Neighbors.end();it++)
	path[i][(*it)->label]=i;

	while(1)
	{
		closest=FindNearest(i,V);
//		printf("%d\n",closest);	
		if(closest<0)
			break;
		V.erase(closest);
		for(vector<Node* >::iterator it=vertice[closest].Neighbors.begin();it!=vertice[closest].Neighbors.end();it++)
		{
//			Distances[i][it->label]=((Distances[i][closest]+Edges[closest][it->label])<Distances[i][it->label])?(Distances[i][closest]+Edges[closet][it->label]): Distances[i][it->label];
			if((*it)->label==i)
				continue;

			if(Distances[i][(*it)->label]<0)
			{	
				Distances[i][(*it)->label] = Distances[i][closest]+Edges[closest][(*it)->label];
				path[i][(*it)->label]=closest;
			}
			else if(Distances[i][(*it)->label]>(Distances[i][closest]+Edges[closest][(*it)->label]))
			{	
				Distances[i][(*it)->label] = Distances[i][closest]+Edges[closest][(*it)->label];
				path[i][(*it)->label]=closest;
			}
		}
	}
	
 
		

}










static bool mygreater(const pair<string, int>& a,const pair<string, int>& b)
{
	if(a.second<b.second)
		return true;
	else if(a.second>b.second)
		return false;
	else
		return a.first<b.first;
}


int main(void)
{
	int a,b;
	double dist;
	scanf("%d %d %lf",&a,&b,&dist);

	map<int, string> cities;
	cities[0]="Allentown";
	cities[1]="Bobtown";
	cities[6]="Charlestown";
	cities[7]="Downville";
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		nmap[i][j]=-1;
	
	}
	vector <pair<pair<int,int>,double> >signs;
	signs.push_back(make_pair(make_pair(0,3),2.17));
	signs.push_back(make_pair(make_pair(3,2),0.45));
	signs.push_back(make_pair(make_pair(4,3),3.14));
	vector <pair<string, int> > Result;
	
	nmap[0][1]=7.12;
	nmap[0][2]=8.34;
	nmap[0][3]=5.33;
	nmap[0][4]=5.36;
	nmap[1][2]=4.21;
	nmap[1][6]=6.99;
	nmap[1][7]=10.26;
	nmap[2][3]=2.74;
	nmap[2][6]=5.04;
	nmap[3][4]=4.12;
	nmap[3][5]=7.72;
	nmap[3][6]=5.71;
	nmap[4][5]=8.94;
	nmap[4][6]=10.29;
	nmap[5][6]=5.47;
	nmap[5][7]=8.55;
	nmap[6][7]=6.01;






	for(int i=0;i<8;i++)
		for(int j=0;j<i;j++)
			nmap[i][j]=nmap[j][i];


	Graph myg=Graph(nmap,8);
//	Graph((double(*)[30])nmap,8);
	myg.setShortestPath();
//	myg.Dijkstra(0);
//	myg.Dijkstra(1);
	for (int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
		printf("%.2lf	",myg.Distances[i][j]);
		if(j==7)
			printf("\n");
		}
	printf("------------------------------------------------------------\n");
	for (int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
		printf("%05d	",myg.path[i][j]);
		if(j==7)
			printf("\n");
		}	

	for ( vector <pair<pair<int,int>,double> >::const_iterator it= signs.begin();it!=signs.end();it++)
	{
		Result.clear();
		for (map<int, string>::const_iterator jt=cities.begin();jt!=cities.end();jt++)
		{	
			if(myg.path[jt->first][it->first.first]==it->first.second)
			{
				Result.push_back(make_pair(jt->second,(int)round(myg.Distances[jt->first][it->first.first]-it->second)));	
			}
		}
		cout<<endl;
		sort(Result.begin(),Result.end(),mygreater);
		for( vector <pair<string, int> >::const_iterator it=Result.begin();it!=Result.end();it++)
			cout<<it->first<<"  "<<it->second<<endl;	
		
	
	}	
	

//	for(map<int,string>::const_iterator it=cities.begin();it!=cities.end();it++)
		
	
	return 0;
}
