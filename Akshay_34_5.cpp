#include<iostream>
using namespace std;
int H[50];
int size=-1;

int parent(int i)
{
	return (i-1)/2;

}

int leftChild(int i)
{
	return ((2*i)+1);
}

int rightChild(int i)
{
	return ((2*i)+2);
}

void shiftUp(int i)
{
	while(i>0&&H[parent(i)]<H[i])
	{
		swap(H[parent(i)],H[i]);
		i=parent(i);
	}
}

void shifDown(int i)
{
	int maxIndex=i;
	int l=leftChild(i);
	if(l<=size && H[l]>H[maxIndex])
	{
		maxIndex=l;
	}
	
	int r=rightChild(i);
	if(r<=size&&H[r]>H[maxIndex])

	{
		maxIndex=r;
	}
	if(i!=maxIndex)
	{
	swap(H[i],H[maxIndex]);
	shifDown(maxIndex);
	}
}

void insert(int p)
{
	size=size+1;
	H[size]=p;
	shiftUp(size);
}

int extractMax()
{
	int result=H[0];
	H[0]=H[size];
	size=size-1;

	shifDown(0);
	return result;
}

void changePriority(int i,int p)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp){
	shiftUp(i);
	}
	else
	{
	   shifDown(i);
	}
}

int getMax()
{
	return H[0];
}

void remove(int i)
{
	H[i]=getMax()+1;
	shiftUp(i);
	extractMax();
}

int main()
{
	int data,pos,pos1,element,c,c1,ch;
	int i=0,j=0,k=0,l=0;
	do
	{
		cout<<"\n1.Add the element in the queue\n2.Priority Queue\n3.Node with the Maximum Priority\n4.Priority Queue After Extracting Maximum\n5.Change Priority\n6.Remove the element \n";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			     do{
				cout<<"\nEnter the data:";
				cin>>data;
				insert(data);
				cout<<"\n Add more data?? If yes then ress 1!:";
				cin>>c;
				}while(c==1);
				break;
			case 2:
				cout<<"Priority Queue:";
				while(i<=size)
				{
				cout<<H[i]<<" ";
				i++;
				}
				break;
			case 3:
				cout<<"\n";
				cout<<"Node with maximum priority:"<<extractMax()<<endl;
				break;
			case 4:
				cout<<"Priority queue After extracting maximum:";
				while(j<=size)
				{
					cout<<H[j]<<" ";
					j++;
				}
				break;
			case 5:
				cout<<endl;
			
			cout<<"Enter the position and element to chanmge the priority\n";
			cin>>pos>>element;
			changePriority(pos,element);
			cout<<"Priority Queue After priority change:";
			while(k<=size)
			{
             			cout<<H[k]<<" ";
		        	k++;
			}
			break;
			case 6:
			cout<<endl;
			cout<<"Enter the position to delete from priority queue\n";
			cin>>pos1;
			remove(pos1);
			cout<<"Priority queue after removing the element:";
			while(l<=size)
			{
				cout<<H[l]<<" ";
				l++;
			}
			break;
		}
		cout<<"\nDo you want to continue if yes then press 1:";
		cin>>c1;
	}while(c1==1);

return 0;

}