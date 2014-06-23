#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <stack>

using namespace std;
class DRSWmath
{
	public: 
		vector<map<int,string> > subelements;
//		int size;
		string DRWSscript;
		vector<int>  parseFromString(const string& str);
		DRSWmath(const string& str);
		map<int,string> calculation(const vector<int> &ele);
		map<int,string> combineResult(vector<map<int,string> >& subresults);
		map<int,string>  generateSubelements(const string& str);
};

map<int,string> DRSWmath::calculation(const vector<int> &ele)
{
	if(ele.size()==1)
	{
		map<int,string> result;
		char value[10];
		sprintf(value,"%d",*(ele.begin()));
		result[*(ele.begin())]=value;
		return result;
	}
	else
	{
		vector<int> E=ele;
		int First=*(ele.rbegin());
		char value[10];
		sprintf(value,"%d",First);
		E.pop_back();
		map<int,string> subresult=calculation(E);
		map<int,string> result;
		for(map<int,string>::iterator it=subresult.begin();it!=subresult.end();it++)
		{
			result[(it->first)*First]=it->second+"*"+string(value);
			result[it->first-First]=it->second+"-"+string(value);
			result[it->first+First]=it->second+"+"+string(value);
		}
		return result;
	}
	 
}


vector<int> DRSWmath::parseFromString(const string& str)
{
	vector<string> lines;
	vector<int> Numericline;
 	char* cstr=new char[str.size()+1];
	strcpy(cstr,str.c_str());
	char * pch=strtok(cstr," ");
//	printf("%s\n",cstr);
	while(pch!=NULL)
	{
		Numericline.push_back(atoi(pch));
		pch=strtok(NULL," ");
		
	}
	delete [] cstr;
	return Numericline;		



}








DRSWmath::DRSWmath(const string& str):DRWSscript(str)
{


}

map<int,string> DRSWmath::combineResult(vector<map<int,string> >& subresults)
{
//	printf("hi\n");
//	printf("%d\n",subresults.size());
	if(subresults.size()==1)	
		return *(subresults.begin());
	else
	{
		map<int,string> result;
		map<int,string> rightest=*(subresults.rbegin());
//		printf("%s\n",rightest.begin()->second.c_str());
		subresults.pop_back();
		map<int,string> leftresult=combineResult(subresults);

//		printf("hello\n");
//		printf("%s\n",leftresult.begin()->second.c_str());
		for (map<int,string>::const_iterator it=leftresult.begin();it!=leftresult.end();it++)
		{
//			printf("%s\n",it->second.c_str());
			for(map<int,string>::const_iterator jt=rightest.begin();jt!=rightest.end();jt++)
			{
//				printf("%s\n",jt->second.c_str());
				result[(it->first)*(jt->first)]=it->second+"*"+jt->second;
				result[(it->first)-(jt->first)]=it->second+"-"+jt->second;
				result[(it->first)+(jt->first)]=it->second+"+"+jt->second;
			}
		}
		return result;
	}

}

map<int,string>  DRSWmath::generateSubelements(const string& str)
{
	vector<map<int,string> >subresults;
	stack<char> parentheses;
	size_t start=0;
	size_t len=0;
	for(int i=0;i<str.size();i++)
	{
		if(str.at(i)=='(')
		{
			if(i!=start && parentheses.empty())
			{
				len=i-start;
				string element=str.substr(start,len);
				vector<int> toCalculate=parseFromString(element);
				if(!toCalculate.empty())
					subresults.push_back(calculation(toCalculate));
				start=i+1;
			}
			
			parentheses.push('(');
		}
		else if(str.at(i)==')')
		{
			parentheses.pop();
			if(parentheses.empty())
			{
				len=i-start;
				string element=str.substr(start,len);
//				printf("%s",element.c_str());
				map<int,string> insertvalue=generateSubelements(element);
				for(map<int,string>::iterator it=insertvalue.begin();it!=insertvalue.end();it++)
					it->second="("+it->second+")";
				subresults.push_back(insertvalue);
				start=i+1;
			}
			
		}
		else if(i==str.size()-1 && i>=0)
		{
			len=i+1-start;
			string element=str.substr(start,len);
			vector<int> toCalculate=parseFromString(element);
			if(!toCalculate.empty())
				subresults.push_back(calculation(toCalculate));
		}
	}
//	printf("before combine result\n");
	return combineResult(subresults);
}

int main(void)
{
	string line="";
	vector<string> input;
	while(line.compare("0")!=0)
	{
		getline(cin,line);
		input.push_back(line);
	}

	DRSWmath myMath=DRSWmath("1 1");
	vector<int> test(6,2);
	map<int,string> result= myMath.calculation(test);
/*	for (map<int, string>::iterator it=result.begin();it!=result.end();it++)
		cout<<it->first<<"="<<it->second<<endl;
*/	
	map<int,string>testresult=myMath.generateSubelements("1 (2 (3 4) 5) 6");
	for (map<int, string>::iterator it=testresult.begin();it!=testresult.end();it++)
		cout<<it->first<<"="<<it->second<<endl;
	




//	vector<vector<int> >testparse=myMath.parseFromString("1 2 (3 4) 5 6");
	
	return 0;
}
