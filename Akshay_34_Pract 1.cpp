#include<iostream>
using namespace std;

struct nodestack
{
int data;
nodestack *next;
};
class Stack
{


public:
nodestack *top;
void createStack();
void push(int);
int pop();
bool isEmpty();
int stackTop();
};
void Stack::createStack()
{
top=NULL;
}
bool Stack::isEmpty()
{
return (top==NULL);
}
void Stack::push(int item)
{
nodestack *newnode;
newnode=new(nodestack);
if(newnode==NULL)
cout<<"cannot allocate memory"<<endl;
newnode ->data=item;
newnode ->next=top;
top=newnode;
}
int  Stack::pop()
{
nodestack *delnode;
if(isEmpty()){

cout<<"stack is empty"<<endl;

return 1;

}

else
{
delnode=top;

top=delnode->next;
delete(delnode);
}
return 0;
}

int main()
{
char input[20];
char ch;
int i,flag=0;
cout<<"Enter the string:";
cin>>input;
Stack s;
s.createStack();
for(i=0;input[i]!='\0';i++)
{
ch=input[i];
if(ch=='(')
s.push(ch);
else
if(ch==')')
flag=s.pop();
}
if(s.isEmpty() and flag==0)
cout<<"Well Formedness of Paranthesis "<<endl;
else
cout<<"Not Well formedness of paranthesis"<<endl;
return 0;
}
