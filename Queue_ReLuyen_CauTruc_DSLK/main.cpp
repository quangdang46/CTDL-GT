#include <iostream>
#include <string.h>
using namespace std;
struct Customer
{
	int id;
	char name[250];	
};
struct Node
{
	Customer *data;
	Node *pLink;
};
struct QUEUE
{
	Node *pFront;
	Node *pRear;
};
void Initialize(QUEUE &queue);
Node * CreateNode(Customer *d);
void Enqueue(QUEUE &queue,Customer *d);
Node *Dequeue(QUEUE &queue);
bool IsEmpty(QUEUE queue);

int main(int argc, char** argv) {
	QUEUE queue;
	Initialize(queue);
	
	Customer *c1=new Customer;
	c1->id=1;
	strcpy(c1->name,"Obama");
	Enqueue(queue,c1);
	
	Customer *c2=new Customer;
	c2->id=2;
	strcpy(c2->name,"Putin");
	Enqueue(queue,c2);
	
	Customer *c3=new Customer;
	c3->id=3;
	strcpy(c3->name,"Trump");
	Enqueue(queue,c3);
	
	while(IsEmpty(queue)==false)
	{
		Node *p=Dequeue(queue);
		Customer *c=p->data;
		cout<<c->id<<"\t"<<c->name<<"\n";
	}
	
	return 0;
}
void Initialize(QUEUE &queue)
{
	queue.pFront=queue.pRear=NULL;
}
Node * CreateNode(Customer *d)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat o nho";
		exit(0);
	}
	pNode->data=d;
	pNode->pLink=NULL;
}
void Enqueue(QUEUE &queue,Customer *d)
{
	Node *pNode=CreateNode(d);
	if(queue.pFront==NULL)
	{
		queue.pFront=queue.pRear=pNode;
	}
	else
	{
		queue.pRear->pLink=pNode;
		queue.pRear=pNode;
	}
}
Node *Dequeue(QUEUE &queue)
{
	if(queue.pFront==NULL)
	{
		cout<<"Hang doi het roi";
		exit(0);
	}
	Node *p=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	p->pLink=NULL;
	return p;
}
bool IsEmpty(QUEUE queue)
{
	return queue.pFront==NULL;
}




