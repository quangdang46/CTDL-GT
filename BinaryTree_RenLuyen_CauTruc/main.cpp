#include <iostream>
#include <string.h>
using namespace std;
struct SanPham
{
	int ma;
	char ten[250];
	float gia;
};
struct TNode
{
	SanPham *Value;
	TNode *pLeft;
	TNode *pRight;
};
typedef TNode* BTree;
TNode *CreateNode(SanPham *v)
{
	TNode *node=new TNode;
	node->Value=v;
	node->pLeft=node->pRight=NULL;
	return node;
}
void InsertNode(BTree &root,SanPham *v)
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
			if(tmp->Value->ma>node->Value->ma)
			{
				tmp=tmp->pLeft;
			}
			else
			{
				tmp=tmp->pRight;
			}
		}
		if(parent->Value->ma>node->Value->ma)
		{
			parent->pLeft=node;
		}
		else
		{
			parent->pRight=node;
		}
	}
}
void PostOrder(BTree root)
{
	if(root!=NULL)
	{
		PostOrder(root->pLeft);
		PostOrder(root->pRight);
		cout<<root->Value->ma<<"\t"<<root->Value->ten<<"\t"<<root->Value->gia<<"\n";
	}
}
TNode *Search(BTree root,int ma)
{
	if(root==NULL || root->Value->ma==ma)
		return root;
	else
	{
		if(ma<root->Value->ma)
		{
			return Search(root->pLeft,ma);
		}
		else if(ma>root->Value->ma)
		{
			return Search(root->pRight,ma);
		}
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BTree root=NULL;
	SanPham *s1=new SanPham;
	s1->ma=100;
	strcpy(s1->ten,"Coca");
	s1->gia=15.5f;	
	InsertNode(root,s1);
	
	SanPham *s2=new SanPham;
	s2->ma=50;
	strcpy(s2->ten,"Pepsi");
	s2->gia=20.2f;	
	InsertNode(root,s2);
	
	SanPham *s3=new SanPham;
	s3->ma=200;
	strcpy(s3->ten,"Redbull");
	s3->gia=23.9f;	
	InsertNode(root,s3);
	cout<<"Danh sach San pham sau khi xuat dung PostOrder:\n";
	PostOrder(root);
	cout<<"Nhap ma de tim kiem:";
	int ma;
	cin>>ma;
	TNode *node=Search(root,ma);
	if(node==NULL)
	{
		cout<<"Khong tim thay san pham co ma ="<<ma;
	}
	else
	{
		cout<<"Tim thay san pham co ma ="<<ma<<", chi tiet:\n";
		SanPham *s=node->Value;
		cout<<s->ma<<"\t"<<s->ten<<"\t"<<s->gia;
	}
	return 0;
}
