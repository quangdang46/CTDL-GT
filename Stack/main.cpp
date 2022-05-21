#include <iostream>
#define MAX_OF_STACK 10
using namespace std;
int stack[MAX_OF_STACK];
int top=-1;
//prototype
void push(int value);
int pop();
void H10toH2(int n);

int main(int argc, char** argv) {
	
	int n=13;
	H10toH2(n);
	cout<<"\n";
	
	push(5);
	push(8);
	push(3);
	int t=pop();//lay phan tu tren cung cua Stack
	cout<<t<<"\n";
	t=pop();
	cout<<t<<"\n";
	t=pop();
	cout<<t<<"\n";
	t=pop();
	cout<<t<<"\n";
	
	return 0;
}
void push(int value)
{
	if(top<MAX_OF_STACK)
	{
		top=top+1;
		stack[top]=value;
	}
	else
	{
		cout<<"Stack da day!";
		exit(0);
	}
}
int pop()
{
	int value;
	if(top>=0)
	{
		value=stack[top];
		top=top-1;
	}
	else
	{
		cout<<"Stack rong!";		
		exit(0);
	}
	return value;
}
void H10toH2(int n)
{
	if(n>0)
	{
		int sd=n%2;
		H10toH2(n/2);
		cout<<sd;
	}
}
