
#include<iostream>
using namespace std;
#define MAX 10
#define SIZE 10
#define FALSE 0
#define TRUE 1
struct hashtable
{
	int chain;
	long int key;
	string name;
}s[MAX];
class hasht
{
	public:
	int hash(int telno);
};
int hasht::hash(int telno)
{
	int h;
	h=telno % MAX;
	return h;
}
int main()
{
	int i,flag1=0,ch,ch1,no1,h,c,index,k,temp,ch3;
	int data[SIZE],flag[SIZE],chain[SIZE],j,x,op,loc;
	string sname;
	string name1[SIZE];
	hasht t;
	for(i=0;i<MAX;i++)
	{
		s[i].key=-1;
		s[i].chain=-1;
		s[i].name='_';
	}
	do
	{
		for(j=0;j<MAX;j++)
		{
			if(s[j].key==-1)
			break;
		}
		if(j==MAX)
		{
			cout<<"\n hash table is full ";
			break;
		}
		cout<<"\n Enter the telephone no : ";
		cin>>no1;

		cout<<"Enter the name : ";
		cin>>sname;

		h=t.hash(no1);
		c=-1;
		index=h;
		do
		{
	            if(s[h].key==-1)
		    {
		 	flag1=1;
			s[h].key=no1;
			s[h].name=sname;

			if(c!=-1)
			s[c].chain=h;
		   }
		else if(t.hash(s[h].key)==index)
		c=h;
		h=t.hash(h+1);
		}while(flag1==0 && h<MAX);

		flag1=0;
		cout<<"--------------";
		cout<<"\nINDEX"<<"\t"<<"TELEPHONENO"<<"\t"<<"NAME"<<"\t"<<"CHAIN"<<"\n";
		for(i=0;i<MAX;i++)
		cout<<i<<"\t"<<s[i].key<<"\t\t"<<s[i].name<<"\t"<<s[i].chain<<"\n";
		cout<<"--------------";
   		cout<<"\nDo you want to continue[0/1]";
		cin>>ch;
	}while(ch==1);
	return 0;
}
