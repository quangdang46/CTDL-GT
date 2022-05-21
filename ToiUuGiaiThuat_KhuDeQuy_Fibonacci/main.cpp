#include <iostream>
using namespace std;
int fib(int n)
{
	if(n<=2)
		return 1;
	return fib(n-1)+fib(n-2);
}
int fib2(int n)
{
	int f1=1,f2=1;
	if(n<=2)
		return 1;
	int i=3,f3;
	while(i<=n)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
		i++;
	}
	return f3;
}

int main(int argc, char** argv) {
	int n;
	cout<<"Nhap n:";
	cin>>n;
	//int f=fib(n);
	//cout<<"fib("<<n<<")="<<f;
	int f=fib2(n);
	cout<<"fib2("<<n<<")="<<f;
	return 0;
}
