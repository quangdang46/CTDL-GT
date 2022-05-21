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
	int tmp=n;
	while(tmp>0)
	{
		int sd=tmp%2;
		tmp=tmp/2;	
		push(sd);
	};
	while(top!=-1)
	{
		int v=pop();
		cout<<v;
	}	
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
