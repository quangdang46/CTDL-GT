#include <iostream>
using namespace std;
struct Node
{
	double data;
	Node *pLink;
};
struct QUEUE
{
	Node *pFront;
	Node *pRear;	
};
void Initialize(QUEUE& queue);
Node *CreateNode(double d);
void Enqueue(QUEUE& queue,double d);
double Dequeue(QUEUE&queue);
bool IsEmpty(QUEUE queue);

int main(int argc, char** argv) {
	QUEUE queue;
	Initialize(queue);
	Enqueue(queue,9.5);
	Enqueue(queue,5.2);	
	Enqueue(queue,7.3);
	while(IsEmpty(queue)==false)	
	{
		double d=Dequeue(queue);
		cout<<d<<"\n";
	}
	return 0;
}
void Initialize(QUEUE& queue)
{
	queue.pFront=queue.pRear=NULL;
}
Node *CreateNode(double d)
{
	Node *pNode=new Node;
	if(pNode==NULL)
	{
		cout<<"Loi cap phat bo nho";
		exit(0);
	}
	pNode->data=d;
	pNode->pLink=NULL;
	return pNode;
}
void Enqueue(QUEUE& queue,double d)
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
double Dequeue(QUEUE&queue)
{
	if(queue.pFront==NULL)
	{
		cout<<"Hang doi Rong";
		exit(0);
	}
	double d=queue.pFront->data;
	Node *pDel=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	pDel->pLink=NULL;
	delete pDel;
	return d;
}
bool IsEmpty(QUEUE queue)
{
	return queue.pFront==NULL;
}

