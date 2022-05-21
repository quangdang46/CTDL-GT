#include <iostream>
#include <string.h>
using namespace std;
struct SinhVien
{	
	int ma;
	char ten[250];
};
struct NodeSinhVien
{
	SinhVien *Value;
	NodeSinhVien *pLeft;
	NodeSinhVien *pRight;	
};
typedef NodeSinhVien* BinarySearchTree;

struct LopHoc
{
	int ma;
	char ten[250];
};
struct NodeLopHoc
{
	LopHoc *Value;
	BinarySearchTree root;
	NodeLopHoc *pNext;
	NodeLopHoc *pPrevious;
};
struct DLink
{
	NodeLopHoc *pHead;
	NodeLopHoc *Tail;	
};
NodeSinhVien *CreateNodeSinhVien(SinhVien *sv);
void InitialBinarySearchTree(BinarySearchTree &root);
void InsertSinhVien(BinarySearchTree &root,SinhVien *sv);
void Inorder(BinarySearchTree root);

NodeLopHoc *CreateNodeLopHoc(LopHoc *lh);
void InitialDLink(DLink &dlink);
void InsertLopHoc(DLink &dlink,NodeLopHoc *node);
void PrintLopHoc(DLink dlink);
NodeLopHoc *SearchNodeLopHoc(DLink dlink,int ma);


int main(int argc, char** argv) {
	DLink link;
	InitialDLink(link);
	
	LopHoc*lop1=new LopHoc;
	lop1->ma=1;
	strcpy(lop1->ten,"K19411");
	NodeLopHoc *node1=CreateNodeLopHoc(lop1);
	InsertLopHoc(link,node1);
	
	LopHoc*lop2=new LopHoc;
	lop2->ma=2;
	strcpy(lop2->ten,"K17411");
	NodeLopHoc *node2=CreateNodeLopHoc(lop2);
	InsertLopHoc(link,node2);	
	
	LopHoc*lop3=new LopHoc;
	lop3->ma=3;
	strcpy(lop3->ten,"K18406");
	NodeLopHoc *node3=CreateNodeLopHoc(lop3);
	InsertLopHoc(link,node3);	
	
	PrintLopHoc(link);
	
	BinarySearchTree dsSV1;
	InitialBinarySearchTree(dsSV1);
	
	SinhVien *sv1=new SinhVien;
	sv1->ma=10;
	strcpy(sv1->ten,"Tran Thi An");
	InsertSinhVien(dsSV1,sv1);
	
	
	SinhVien *sv2=new SinhVien;
	sv2->ma=5;
	strcpy(sv2->ten,"Ho Van Tai");
	InsertSinhVien(dsSV1,sv2);
	
	SinhVien *sv3=new SinhVien;
	sv3->ma=20;
	strcpy(sv3->ten,"Tran Pham Man Nhi");
	InsertSinhVien(dsSV1,sv3);
	
	node1->root=dsSV1;
	
	int ml;
	cout<<"Nhap ma lop:";
	cin>>ml;
	NodeLopHoc *result=SearchNodeLopHoc(link,ml);
	if(result!=NULL)
	{
		cout<<"Tim thay lop "<<result->Value->ten<<"\n";
		cout<<"Danh sach Sinh vien cua Lop:\n";
		Inorder(result->root);
	}
	return 0;
}
NodeSinhVien *CreateNodeSinhVien(SinhVien *sv)
{
	NodeSinhVien *node=new NodeSinhVien;
	node->Value=sv;
	node->pLeft=node->pRight=NULL;
	return node;
}
void InitialBinarySearchTree(BinarySearchTree &root)
{
	root=NULL;
}
void InsertSinhVien(BinarySearchTree &root,SinhVien *sv)
{
	NodeSinhVien *node=CreateNodeSinhVien (sv);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		NodeSinhVien *tmp=root;
		NodeSinhVien *parent=NULL;
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
		if(parent->Value>node->Value)
			parent->pLeft=node;
		else
			parent->pRight=node;
	}
}
void Inorder(BinarySearchTree root)
{
	if(root!=NULL)
	{
		Inorder(root->pLeft);
		cout<<root->Value->ma<<"\t"<<root->Value->ten<<"\n";
		Inorder(root->pRight);		
	}
}

NodeLopHoc *CreateNodeLopHoc(LopHoc *lh)
{
	NodeLopHoc *node=new NodeLopHoc;
	node->Value=lh;
	node->root=NULL;
	node->pNext=node->pPrevious=NULL;
	return node;
}
void InitialDLink(DLink &dlink)
{
	dlink.pHead=dlink.Tail=NULL;
}

void InsertLopHoc(DLink &dlink,NodeLopHoc *node)
{
	if(dlink.Tail==NULL)
	{
		dlink.pHead=dlink.Tail=node;
	}
	else
	{
		dlink.Tail->pNext=node;
		node->pPrevious=dlink.Tail;
		dlink.Tail=node;
	}
}
void PrintLopHoc(DLink dlink)
{
	NodeLopHoc *node=dlink.pHead;
	while(node!=NULL)
	{
		LopHoc *lh=node->Value;
		cout<<lh->ma<<"\t"<<lh->ten<<"\n";
		node=node->pNext;
	}
}
NodeLopHoc *SearchNodeLopHoc(DLink dlink,int ma)
{
	NodeLopHoc *node=dlink.pHead;
	while(node!=NULL)
	{
		if(node->Value->ma==ma)
			break;
		node=node->pNext;
	}
	return node;
}
