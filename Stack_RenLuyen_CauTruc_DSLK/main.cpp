#include <iostream>
#include <string.h>
using namespace std;
struct Device
{
	int id;
	char name[250];	
};
struct Node
{
	Device *data;
	Node *pLink;	
};
typedef Node * STACK;
void Initialize(STACK &stack)
{
	stack=NULL;
}
Node * CreateNode(Device *d)
{
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}
void Push(STACK &stack,Device *d)
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
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	return pDel;
}
bool IsEmpty(STACK stack)
{
	return stack==NULL;
}

int main(int argc, char** argv) {
	STACK stack;
	Initialize(stack);
	
	Device *d1=new Device;
	d1->id=1;
	strcpy(d1->name,"Adapter Wifi");
	Push(stack,d1);
	
	Device *d2=new Device;
	d2->id=2;
	strcpy(d2->name,"Optical Mouse");
	Push(stack,d2);
	
	Device *d3=new Device;
	d3->id=3;
	strcpy(d3->name,"USB");
	Push(stack,d3);
	
	while(IsEmpty(stack)==false)
	{
		Node * n=Pop(stack);
		Device *d=n->data;
		cout<<d->id<<"\t"<<d->name<<"\n";
	}
	
	return 0;
}
