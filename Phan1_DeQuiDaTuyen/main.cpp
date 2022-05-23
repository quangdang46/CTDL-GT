#include <iostream>
using namespace std;

void print_array(int arr[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
void print_permuitation(int arr[], int n, int i)
{
	print_array(arr,n);	
	for (int j=i+1;j<n;j++)
	{
		if(arr[i]>arr[j])
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		print_permuitation(arr,n,i+1);
	}
}
void SapXep(int arr[], int n, int i)
{
	for (int j = i+1;j<n;j++)
	{
		if (arr[i]>arr[j])
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		SapXep(arr,n,i+1);
	}
}
int main(int argc, char** argv) {
	int M[5] = {10,2,5,3,4};
	//print_permuitation(M,5,0);
	SapXep(M,5,0);
	print_array(M,5);
	return 0;
}
