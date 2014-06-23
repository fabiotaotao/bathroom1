#include <stdio.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
map<int,long> A;
vector<int> C;
map <int,long> B;//B[k] denotes the number of trees having nodes less or equal to k, B[-1]=0,B[0]=1,B[1]=2,so B[k-1]<n+1<=B[k] for the # n tree with k nodes

struct Node
{
	long orderno;
	int NofNodes;
};




class TreeNode
{
 	public:
	TreeNode(long n,int k);
	~TreeNode();
	long orderno;
	int NofNodes;
	TreeNode* LeftChild;
	TreeNode* RightChild;
	static void CreateChildren();
        static Node CreateLeftChild(long&, int&);
	static Node CreateRightChild(long&, int&);
	static string printTree(TreeNode* );
}; 

string TreeNode::printTree(TreeNode* TN)
{
	if(TN->orderno!=0)
	{
		string result="x";
		if(TN->LeftChild!=NULL)
			result="("+TreeNode::printTree(TN->LeftChild)+")"+result;
		if(TN->RightChild!=NULL)
			result=result+"("+TreeNode::printTree(TN->RightChild)+")";
		return result;
	}
	else
	return "";
}



TreeNode::TreeNode(long n,int k)
{
	orderno=n;
	NofNodes=k;
	if(n==1||n==0)
	{
		LeftChild=NULL;
		RightChild=NULL;
	}
	else
	{
		Node Leftnode=CreateLeftChild(n,k);
		Node Rightnode=CreateRightChild(n,k);
		
		if(Leftnode.orderno==0)
		{	
			LeftChild=NULL;
		}
		else
		{
			LeftChild = new TreeNode(Leftnode.orderno, Leftnode.NofNodes);
		}
		if(Rightnode.orderno==0)
		{	
			RightChild=NULL;
		}
		else
		{
			RightChild = new TreeNode(Rightnode.orderno,Rightnode.NofNodes);
		}	
	}	
}

TreeNode:: ~TreeNode()
{
	if(this->LeftChild!=NULL)
		delete this->LeftChild;
	if(this->RightChild!=NULL)
		delete this->RightChild;	

}
/*
void TreeNode::CreateChildren()
{
	if(this->orderno==1 ||  this->orderno==0)
		{
			this->LeftChild = NULL;
			this->RightChild = NULL;
		}
	else
		{
			this->LeftChild = new TreeNode(CreateLeftChild(this->orderno, this->NofNodes));
			this->RightChild = new TreeNode(CreateRightChild(this->orderno, this->NofNodes));
		}

}
*/



void setB(int n)
{
	if(n==-1)
		B[-1]=0;
	else if(n==0)
		B[0]=1;	
	else if (n==1)
		B[1]=2;	
	else
	{
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=(B[n-1-i]-B[n-2-i])*(B[i]-B[i-1]);
//			sum+=A(n-1-i)*A(i);
		B[n]=B[n-1]+sum;	
	
	}
}

int  CreateB(long &n)//get the number of nodes from order n
{
	B.clear();
	
	setB(-1);
	int k=-1;
	while((B[k]-1)<n)
	{
		k++;
		setB(k);
	}
	return k;
}

int getKfromB(long& n)
{
	int k=-1;
	while((B[k]-1)<n)
	{
		k++;
	}
	return k;
}




void SetAfromB(int &n)
{
		
		A[-1]=0;
	for (int i=0;i<=n;i++)
		A[i]=B[i]-B[i-1];

	
//	for (map<int, long>::iterator it=Bt.begin()+1;it!=Bt.end();it++)
//		A[it->first]=it->second-(it-1)->second;

}




Node  TreeNode::CreateLeftChild(long &n,int &k)
//(n,k) is the parent node order number and number of nodes, this function creates the leftchild order number and number of nodes
{
//	printf("left child: %ld,%d\n",n,k);
  	Node nk;
  	long  r=n+1-B[k-1];
  	long res=0;
	int i=0;
	for (i=0;i<k;i++)
	{
		res+=A[i]*A[k-1-i];			
		if(r<=res)
			break;
	}		
/*  	while(res<r)
		{
		res+=A[i]*A[k-1-i];
		i++;
		}*/
 	long r2=r-res+A[i]*A[k-1-i];
//	printf("r: %ld, r2:%ld, res: %ld\n,i=%d, k-1=%d ",r,r2,res,i,k-1);
//	printf("A[k-1-i]=%ld\n",A[k-1-i]);
	if(r2<=A[k-1-i])
		nk.orderno=B[i-1];
	else
//		printf("order in subtree: %d\n",(int)ceil(r2/A[k-1-i])-1);
		nk.orderno=(long)ceil((double)r2/(double)A[k-1-i])+B[i-1]-1;	


 //	nk.orderno=(r2-r2%A[k-1-i])/A[k-1-i]+B[i-1];
 	nk.NofNodes=i;
//	printf("left child: %ld,%d\n",nk.orderno,nk.NofNodes);

	
	return nk;
}

Node TreeNode:: CreateRightChild(long &n,int &k)
//(n,k) is the parent node order number and number of nodes, this function creates the rightchild order number and number of nodes
{
  	Node nk;
  	long r=n+1-B[k-1];
  	long res=0;
	int i=0;
	for(i=0;i<k;i++)
	{
		res+=A[i]*A[k-1-i];
		if(r<=res)
			break;
	}
 /* 	while(res<r)
		{
		res+=A[i]*A[k-1-i];
		i++;
		}*/
 	long r2=r-res+A[i]*A[k-1-i];
//	printf("r=%ld,r2=%ld,res=%ld,k=%d,i=%d",r,r2,res,k,i);
	if(r2<=A[k-1-i])
	nk.orderno=r2+B[k-i-2]-1;
	else
	
	{//	printf("ceil: %d,a value%ld, r2=%ld\n",(int)(ceil((double)r2/(double)A[k-1-i])-1),A[k-1-i],r2);
		nk.orderno=r2-(ceil((double)r2/(double)A[k-1-i])-1)*A[k-1-i]+B[k-i-2]-1; 
	}
//	nk.orderno=A[k-1-i]-r2%A[k-1-i]+B[k-i-2];
 	nk.NofNodes=k-1-i;
//	printf("right Child %ld,%d\n",nk.orderno,nk.NofNodes);

	return nk;
}

int main(void)
{
	long n;
	scanf("%ld",&n);
//	n=2;
	int k=CreateB(n);
	SetAfromB(k);
//	printf("k=%d\n b[%d] = %ld\na[%d]=%ld\n",k,k-1,B[k-1],k-1,A[k-1]);
	TreeNode tree(n,k);
	printf("%ld: %s\n",n,	TreeNode::printTree(&tree).c_str());
//	TreeNode emptyleaf=TreeNode::CreateLeftChild(n,k);
/*	for (long i=0;i<n;i++)
	{
		int k=getKfromB(i);
		TreeNode tree(i,k);
		printf("%ld,%s\n",i,TreeNode::printTree(&tree).c_str());
	}
*/

	
//	printf("%ld\n",tree.LeftChild->LeftChild->orderno);
//	CreateB(n);
//	printf("k=%d\n b[%d] = %ld\na[%d]=%ld\n",k,k-1,B[k-1],k-1,A[k-1]);
//	printf("emptyleaf orderno:%ld,number:%d\n",emptyleaf.orderno,emptyleaf.NofNodes);
//	printf("%s\n",TreeNode::printTree(&tree).c_str());

	
}
