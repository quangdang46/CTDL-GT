#include <iostream>
#include <string.h>
#define MAX_OF_QUEUE 10
using namespace std;
struct Customer
{
	int id;
	char name[250];	
};
Customer * queue[MAX_OF_QUEUE];
int rear=-1;
int front=-1;
void enqueue(Customer *c);
Customer * dequeue();
bool isEmpty();

int main(int argc, char** argv) {
	Customer *c1=new Customer;
	c1->id=1;
	strcpy(c1->name,"An");
	
	Customer *c2=new Customer;
	c2->id=2;
	strcpy(c2->name,"Lanh");
	
	Customer *c3=new Customer;
	c3->id=3;
	strcpy(c3->name,"Hanh");
	
	Customer *c4=new Customer;
	c4->id=4;
	strcpy(c4->name,"Phuc");
	
	enqueue(c1);
	enqueue(c2);
	enqueue(c3);
	enqueue(c4);
	while(isEmpty()==false)
	{
		Customer *c=dequeue();
		cout<<c->id<<"\t"<<c->name<<"\n";
	}
	
	return 0;
}
void enqueue(Customer *c)
{
	if(rear<MAX_OF_QUEUE-1)
	{
		rear=rear+1;
		queue[rear]=c;
	}
	else
	{
		cout<<"Queue is full";
		exit(0);
	}
}
Customer* dequeue()
{
	if(front==rear)
	{
		cout<<"Queue is empty";
		exit(0);
	}
	front=front+1;
	Customer *c=queue[front];
	return c;
}
bool isEmpty()
{
	return front==rear;
}
