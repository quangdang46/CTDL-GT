#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
struct Device
{
	int id;
	char name[250];	
};
Device* stack[MAX];
int top=-1;
void push(Device *d);
Device* pop();

int main(int argc, char** argv) {
	Device *d1=new Device;
	d1->id=1;
	strcpy(d1->name,"Mouse");
	push(d1);
	
	Device *d2=new Device;
	d2->id=2;
	strcpy(d2->name,"Usb");
	push(d2);
	
	while(top>=0)
	{
		Device *d=pop();
		cout<<d->id<<"\t"<<d->name<<"\n";
	}
	
	return 0;
}
void push(Device *d)
{
	if(top<MAX)
	{
		top=top+1;
		stack[top]=d;
	}
	else
	{
		cout<<"Stack da day!";
	}
}
Device* pop()
{
	Device *d=NULL;
	if(top>=0)
	{
		d=stack[top];
		top=top-1;
	}
	else
	{
		cout<<"Stack Rong!";
	}
	return d;
}
