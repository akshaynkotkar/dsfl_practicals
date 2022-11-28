#include<iostream>
using namespace std;
typedef struct nodetree
{
int data;
nodetree *left;
nodetree *right;
}root;
class bst
{
root *newnode;
int key;
public:

void insert (root *,root*);
void inorder(root *);
void preorder(root *);
void postorder(root *);

};

//Insert Declaration
void bst::insert(root *root1,root *newnode)
{
if(newnode->data>root1->data)
{
if(root1->right==NULL)
{
root1->right=newnode;
}
else
insert(root1->right,newnode);
}

else
{
if(root1->left==NULL)
{
root1->left=newnode;
}
else
insert(root1->left,newnode);
}
}
// Inorder traversal Declaration.
void bst::inorder(root *newnode)
{
if(newnode!=NULL)
{
inorder(newnode->left);
cout<<newnode->data<<"\t";
inorder(newnode->right);
}
}
// preorder traversal Declaration.
void bst::preorder(root *newnode)
{
if(newnode!=NULL)
{
cout<<newnode->data<<"\t";
inorder(newnode->left);

inorder(newnode->right);
}
}
//postorder traversal Declaration.
void bst::postorder(root *newnode)
{
if(newnode!=NULL)
{

inorder(newnode->left);
inorder(newnode->right);
cout<<newnode->data<<"\t";
}
}



int main()
{
root *newnode,*root1=NULL,*newnode1;
bst binary;
int data1,key,choice,choice1,choice2;
do
{

cout<<"\n1.Insert data\n2.Inorder Traversal\n3.Preorder Traversal \n4.Postorder Traversal";
cout<<"\n\n Enter choice:";
cin>>choice;
switch(choice)
{
case 1:
do 
{
newnode=new nodetree();
cout<<"\n Enter data:";
cin>>data1;
newnode->data=data1;
newnode->right=NULL;
newnode->left=NULL;
if(root1==NULL)
{
root1=newnode;
}
else
{
binary.insert(root1,newnode);
}
cout<<"If you want to add more data press 1:";
cin>>choice1;
}while(choice1==1);
break;
case 2:
binary.inorder(root1);
break;
case 3:
binary.preorder(root1);
break;
case 4:
binary.postorder(root1);
break;
}
cout<<"\nDo you want to continue:";
cin>>choice2;
}while(choice2==1);
return 0;
}


