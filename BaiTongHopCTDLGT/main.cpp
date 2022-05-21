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
typedef NodeSinhVien *BinarySearchTree;
struct LopHoc
{
	int ma;
	char ten[250];
};
struct NodeLopHoc
{
	LopHoc *Value;
	NodeLopHoc *pNext;
	NodeLopHoc *pPrevious;
	BinarySearchTree root;	
};
struct DLink
{
	NodeLopHoc *pHead;
	NodeLopHoc *pTail;	
};
//Prototype SinhVien:
NodeSinhVien *CreateNodeSinhVien(SinhVien *sv);
void InitializeBinarySearchTree(BinarySearchTree &root);
void InsertSinhVien(BinarySearchTree &root,SinhVien *sv);
void Inorder(BinarySearchTree root);

//Prototype Lophoc:
NodeLopHoc *CreateNodeLopHoc(LopHoc *lh);
void InitializeDLink(DLink &link);
void InsertLopHoc(DLink &link,NodeLopHoc *node);
void PrintLopHoc(DLink link);
NodeLopHoc *SearchNodeLopHoc(DLink link, int ml);

int main(int argc, char** argv) {
	DLink link;
	InitializeDLink(link);
	
	LopHoc *lop1=new LopHoc;
	lop1->ma=1;
	strcpy(lop1->ten,"K19411");
	NodeLopHoc *node1=CreateNodeLopHoc(lop1);
	InsertLopHoc(link,node1);

	LopHoc *lop2=new LopHoc;
	lop2->ma=2;
	strcpy(lop2->ten,"K17411");
	NodeLopHoc *node2=CreateNodeLopHoc(lop2);
	InsertLopHoc(link,node2);
	
	LopHoc *lop3=new LopHoc;
	lop3->ma=3;
	strcpy(lop3->ten,"K18406");
	NodeLopHoc *node3=CreateNodeLopHoc(lop3);
	InsertLopHoc(link,node3);
	cout<<"Danh sach Lop hoc:\n";
	PrintLopHoc(link);
	
	BinarySearchTree dsSV1;
	InitializeBinarySearchTree(dsSV1);
	
	SinhVien *sv1=new SinhVien;
	sv1->ma=20;
	strcpy(sv1->ten,"Tran Thi Teo");
	InsertSinhVien(dsSV1,sv1);
	
	SinhVien *sv2=new SinhVien;
	sv2->ma=30;
	strcpy(sv2->ten,"Pham Van Bin");
	InsertSinhVien(dsSV1,sv2);
	
	SinhVien *sv3=new SinhVien;
	sv3->ma=10;
	strcpy(sv3->ten,"Ho Thi Tun");
	InsertSinhVien(dsSV1,sv3);
	
	node1->root=dsSV1;
	
	int ml;
	cout<<"Nhap ma lop muon tim:";
	cin>>ml;
	NodeLopHoc *result=SearchNodeLopHoc(link,ml);
	if(result!=NULL)
	{
		cout<<"Tim thay Lop hoc ="<<result->Value->ten<<":\n";
		Inorder(result->root);
	}
	else
	{
		cout<<"Ko tim thay lop hoc co ma ="<<ml;
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
void InitializeBinarySearchTree(BinarySearchTree &root)
{
	root=NULL;
}
void InsertSinhVien(BinarySearchTree &root,SinhVien *sv)
{
	NodeSinhVien *node=CreateNodeSinhVien(sv);
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		NodeSinhVien*tmp=root;
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
	NodeLopHoc*node=new NodeLopHoc;
	node->Value=lh;
	node->root=NULL;
	node->pNext=node->pPrevious=NULL;
	return node;
}
void InitializeDLink(DLink &link)
{
	link.pHead=link.pTail=NULL;
}
void InsertLopHoc(DLink &link,NodeLopHoc *node)
{
	if(link.pTail==NULL)
	{
		link.pHead=link.pTail=node;
	}
	else
	{
		link.pTail->pNext=node;
		node->pPrevious=link.pTail;
		link.pTail=node;
	}
}
void PrintLopHoc(DLink link)
{
	NodeLopHoc *node=link.pHead;
	while(node!=NULL)
	{
		LopHoc *lop=node->Value;
		cout<<lop->ma<<"\t"<<lop->ten<<"\n";
		node=node->pNext;
	}
}
NodeLopHoc *SearchNodeLopHoc(DLink link, int ml)
{
	NodeLopHoc *node=link.pHead;
	while(node!=NULL)
	{
		LopHoc *lop=node->Value;
		if(lop->ma==ml)
			break;
		node=node->pNext;
	}
	return node;
}
