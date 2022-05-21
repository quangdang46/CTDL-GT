#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 100
using namespace std;
void NhapMang(int M[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		int x=rand()%100;
		M[i]=x;
	}
}
void XuatMang(int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<M[i]<<"\t";
	}
}
struct TNode
{
	int Value;
	TNode *pLeft;
	TNode *pRight;
};
typedef TNode* BTree;
TNode *CreateNode(int v)
{
	TNode *node=new TNode;
	node->Value=v;
	node->pLeft=node->pRight=NULL;
}
void InsertNode(BTree &root,int v)
{
	TNode *node=CreateNode(v);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		BTree tmp=root;
		BTree parent=NULL;
		while(tmp!=NULL)
		{
			parent=tmp;
			if(tmp->Value>node->Value)
			{
				tmp=tmp->pLeft;
			}
			else
			{
				tmp=tmp->pRight;
			}
		}
		if(parent->Value>node->Value)
		{
			parent->pLeft=node;
		}
		else
		{
			parent->pRight=node;
		}
	}
}
void Inorder(BTree root)
{
	if(root!=NULL)
	{
		Inorder(root->pLeft);
		cout<<root->Value<<"\t";
		Inorder(root->pRight);
	}
}
void NapMangLenCay(BTree &root,int M[],int n)
{
	for(int i=0;i<n;i++)
	{
		InsertNode(root,M[i]);
	}
}
int main(int argc, char** argv) {
	int n;
	cout<<"Nhap n:";
	cin>>n;
	int M[n];
	NhapMang(M,n);
	cout<<"Mang Ngau Nhien:\n";
	XuatMang(M,n);
	
	BTree root=NULL;
	NapMangLenCay(root,M,n);
	cout<<"\nMang sau khi sap xep:\n";
	Inorder(root);
	return 0;
}
