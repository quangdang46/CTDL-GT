#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int choose(int n, int k);
int main(int argc, char** argv) {
	int n =5;
	int k =3;
	cout<<choose(n,k);
	return 0;
}
int choose(int n, int k)
{
	if(k==0||n==k)
	{
		return 1;
	}
	return choose(n-1,k) + choose(n-1,k-1);
}
