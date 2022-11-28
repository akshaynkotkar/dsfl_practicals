#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int visited[10];
class graph
{
	int i,j,min,u,v,mincost,cost[10][10],edgs,a,b,n;
public:
	graph()
	{
	edgs=1;
	mincost=0;

	}
	void kruskal(int cost[10][10],int n);
	void read();


};

void graph::read()
{
	cout<<"\nEnter the number of vertices:";
	cin>>n;
	cout<<"\n ENter weight of edgs in the form of edjeceny matrix:";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
			cost[i][j]=9999;
		}
	}
	kruskal(cost,n);
}
void graph:: kruskal(int cost[10][10],int n)
{
	while(edgs<n)
	{
		min=9999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if (cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;

				}

			}

		}
		while(visited[u])
		u=visited[u];
		while(visited[v])
		v=visited[v];
		if(u!=v)
		{
			edgs++;
			cout<<"\nEdgs:"<<a<<"->"<<b<<"\tWeight:"<<min<<"\n";
			mincost=mincost+min;
			visited[v]=u;

		}
		cost[a][b]=cost[b][a]=9999;
  	}
	cout<<"\n Minimum cost= "<<mincost<<"\n";

}
int main(void)
{
	graph obj;
	obj.read();
return 0;
}




 



































































































































































































































































































































