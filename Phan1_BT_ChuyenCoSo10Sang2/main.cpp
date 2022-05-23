#include <iostream>
using namespace std;
void H10ToH2(int n);
int main(int argc, char** argv) {
	H10ToH2(13);
	return 0;
}
void H10ToH2(int n)
{
	if(n>0)
	{
		int sd = n%2;
		n=n/2;
		H10ToH2(n);
		cout<<sd;
	}
}
