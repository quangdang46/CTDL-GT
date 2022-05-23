#include <iostream>

using namespace std;
bool IsEven(int n);
bool IsOdd(int n);
int main(int argc, char** argv) {
	int n;
	cin>>n;
	bool kq = IsEven(n);
	cout<<(kq==true?"so chan":"so le");
	return 0;
}
bool IsEven(int n)
{
	if(n==0) return true;
	else return IsOdd(n-1);
}
bool IsOdd(int n)
{
	return !IsEven(n);
}
