#include <iostream>
#define MAX_OF_QUEUE 10
using namespace std;
int queue[MAX_OF_QUEUE];
int rear=-1;
int front=-1;
//Prototype
void enqueue(int value);
int dequeue();

int main(int argc, char** argv) {
	enqueue(1);
	enqueue(9);
	enqueue(7);
	cout<<dequeue()<<"\n";
	cout<<dequeue()<<"\n";
	cout<<dequeue()<<"\n";
	return 0;
}
void enqueue(int value)
{
	if(rear<MAX_OF_QUEUE-1)
	{
		rear=rear+1;
		queue[rear]=value;
	}
	else
	{
		cout<<"Queue is full";
		exit(0);
	}
}
int dequeue()
{
	if(front==rear)
	{
		cout<<"Queue is empty";
		exit(0);
	}
	front=front+1;
	int value=queue[front];
	return value;
}
