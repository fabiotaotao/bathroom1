#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <deque>


using namespace std;

class graphNode
{
        public:
                char mark;
                bool Traversed;
                bool NS;
                bool EW;
                int segAmounts;
                graphNode();
};

graphNode::graphNode()
{
        mark=' ';
        Traversed=false;
        NS=false;
        EW=false;
        segAmounts=-1;
}

class graph
{
        public:
                unsigned int rowsize;
                unsigned int columnsize;
                vector<string> vecstr;
                deque<pair<int, int> > myQue;
                static graphNode nodes[77][77];
                graph(const vector<string>&);
                
                void HTraverse(int,int,int);
                void VTraverse(int,int,int);
                int Traverse(pair<int,int>,pair<int,int>);
                void initialize();
                void reset();
};

graphNode graph::nodes[77][77];

void graph::reset()
{
        myQue.clear();
        for (int i=0;i<77;i++)
        {
                for(int j=0;j<77;j++)
                {
                        nodes[i][j].mark=' ';
                        nodes[i][j].Traversed=false;
                        nodes[i][j].NS=false;
                        nodes[i][j].EW=false;
                        nodes[i][j].segAmounts=-1;
                }
        }
}       

void graph::initialize()
{       
        reset();
        for (int i=0;i<vecstr.size();i++)
        {
                string str=vecstr[i];
                for(int j=0;j<str.size();j++)
                {
                        nodes[i+1][j+1].mark=str.at(j);
//                        printf("%c",nodes[i+1][j+1].mark=str.at(j));
                }
        }
}       




graph::graph(const vector<string>& grastr):vecstr(grastr)
{
//      rowsize=grastr.size()+1;
//      columnsize=grastr.size()+1;
        reset();
        for (int i=0;i<grastr.size();i++)
        {
                string str=grastr[i];
                for(int j=0;j<str.size();j++)
                {
                        nodes[i+1][j+1].mark=str.at(j);
                }
        }
}

void graph::HTraverse(int m,int l,int seg)
{
        int n=l;
        while(n>=0&& nodes[m][n].EW==false && nodes[m][n].mark==' ')    
        {
                nodes[m][n].EW=true;
                if(nodes[m][n].Traversed==false)
                {
                        nodes[m][n].segAmounts=seg;
                        nodes[m][n].Traversed=true;
                        myQue.push_back(make_pair(m,n));        
               }
                n--;
        }
        n=l+1;
        while(n<77&& nodes[m][n].EW==false && nodes[m][n].mark==' ')
        {
                nodes[m][n].EW=true;
                if(nodes[m][n].Traversed==false)
                {
                        nodes[m][n].segAmounts=seg;
                        nodes[m][n].Traversed=true;
                        myQue.push_back(make_pair(m,n));        
                }
                n++;
        }

        
}

void graph::VTraverse(int l,int n,int seg)
{
        int m=l;
        while(m>=0&& nodes[m][n].NS==false && nodes[m][n].mark==' ')    
        {
                nodes[m][n].NS=true;
                if(nodes[m][n].Traversed==false)
                {
                        nodes[m][n].segAmounts=seg;
                        nodes[m][n].Traversed=true;
                        myQue.push_back(make_pair(m,n));        
                }
                m--;
        }
        m=l+1;
        while(m<77&& nodes[m][n].NS==false && nodes[m][n].mark==' ')
        {
                nodes[m][n].NS=true;
                if(nodes[m][n].Traversed==false)
                {
                        nodes[m][n].segAmounts=seg;
                        nodes[m][n].Traversed=true;
                        myQue.push_back(make_pair(m,n));        
                }
                m++;
        }       
}

int graph::Traverse(pair<int,int> a,pair<int,int> b)
{
        initialize();
        myQue.push_back(a);
        nodes[a.first][a.second].mark=' ';
        nodes[a.first][a.second].Traversed=true;
        nodes[a.first][a.second].segAmounts=0;
        nodes[b.first][b.second].mark=' ';




        while(!myQue.empty())
        {
                pair<int,int> root=*(myQue.begin());
                myQue.pop_front();      
                HTraverse(root.first,root.second,nodes[root.first][root.second].segAmounts+1);
                VTraverse(root.first,root.second,nodes[root.first][root.second].segAmounts+1);
        }

        return nodes[b.first][b.second].segAmounts;

}

int main(void)
{
        int m,n;
        scanf("%d %d",&m,&n);
        vector<string> Graphstr;
        for (int i=0 ; i<m+1; i++)
        {       
                string str;
                getline(cin,str);
                if(i!=0)
                        Graphstr.push_back(str);
        }       
	for (int i=0;i<m;i++)
		printf("%s\n",Graphstr[i].c_str()); 

       
        graph mygraph(Graphstr);
        int r=  mygraph.Traverse(make_pair<int,int>(2,1),make_pair<int,int>(3,2));
        printf("%d\n",r);
/*
        for (int i=0;i<77;i++)
        {
                for (int j=0;j<77;j++)
                {
                        printf("%c ",graph::nodes[i][j].mark);
                        if(j==76)
                                printf("\n");
                }
        }
*/
        return 0;
}


