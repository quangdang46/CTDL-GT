#include <iostream>

using namespace std;
int gcd(int m, int n)
{
	int r;
	if(m<n) return gcd(n,m);
	r=m%n;
	if(r==0)
	{
		return n;
	}
	else
	{
		return gcd(n,r);
	}
}
int main(int argc, char** argv) {
	//int m = 25, n=5;
	//int m = 5, n=25;
	int m = 7, n=3;
	int kq=gcd(m,n);
	cout<<kq;
	return 0;
}
