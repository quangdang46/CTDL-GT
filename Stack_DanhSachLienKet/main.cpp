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
int Pop(STACK &stack)
{
	int d=stack->data;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	delete pDel;
	pDel=NULL;
	return d;
}

int main(int argc, char** argv) {
	STACK stack;
	Initialize(stack);
	Push(stack,113);
	Push(stack,114);
	Push(stack,115);
	cout<<Pop(stack)<<"\n";
	cout<<Pop(stack)<<"\n";
	cout<<Pop(stack)<<"\n";
	return 0;
}
