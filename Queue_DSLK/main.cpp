#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *pLink;
};
struct QUEUE
{
	Node *pFront;
	Node *pRear;
};
void Initialize(QUEUE&queue)
{
	queue.pFront=NULL;
	queue.pRear=NULL;
}
Node *CreateNode(int d)
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
void Enqueue(QUEUE &queue,int d)
{
	Node * pNode=CreateNode(d);
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
int Dequeue(QUEUE &queue)
{
	if(queue.pFront==NULL)
	{
		cout<<"Hang doi da rong";
		exit(0);
	}
	int d=queue.pFront->data;
	Node *pDel=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	pDel->pLink=NULL;
	delete pDel;
	return d;
}

int main(int argc, char** argv) {
	QUEUE queue;
	Initialize(queue);
	Enqueue(queue,5);
	Enqueue(queue,3);
	Enqueue(queue,4);
	cout<<Dequeue(queue)<<"\n";
	cout<<Dequeue(queue)<<"\n";
	cout<<Dequeue(queue)<<"\n";
	cout<<Dequeue(queue)<<"\n";
	return 0;
}
