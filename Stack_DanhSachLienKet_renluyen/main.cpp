#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *pLink;
};
typedef Node* STACK;
void Initialize(STACK &stack)
{
	stack=NULL;
}
Node *CreateNode(int d)
{
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}
void Push(STACK &stack, int d)
{
	Node *pNode=CreateNode(d);
	if(stack==NULL)
	{
		stack=pNode;
	}
	else
	{
		pNode->pLink=stack;
		stack=pNode;
	}
}
Node * Pop(STACK &stack)
{
	if(stack==NULL)
		return NULL;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	return pDel;
}
Node * Top(STACK &stack)
{
	return stack;
}

int main(int argc, char** argv) {
	STACK stack;
	Initialize(stack);
	Push(stack,113);
	Push(stack,114);
	Push(stack,115);
	Node *t=Top(stack);
	cout<<"Node tren cung cua Stack:\n";
	cout<<t<<"\n";
	cout<<t->data<<"\n";
	
	Node *n=Pop(stack);
	cout<<n->data<<"\n";
	n=Pop(stack);
	cout<<n->data<<"\n";
	n=Pop(stack);
	cout<<n->data<<"\n";
	n=Pop(stack);
	if(n==NULL)
	{
		cout<<"Stack da rong!";
	}
	return 0;
}
