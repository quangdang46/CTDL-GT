#include <iostream>
#include <string.h>
using namespace std;
struct SanPham
{
	int ma;
	char ten[250];
	double gia;
};
struct DNode
{
	SanPham *data;
	DNode *pNext;
	DNode *pPrevious;
};
struct DoubleList
{
	DNode *pHead;
};
void Initialize(DoubleList &list)
{
	list.pHead=NULL;
}
DNode *CreateNode(SanPham *d)
{
	DNode *pDNode=new DNode;
	if(pDNode!=NULL)
	{
		pDNode->data=d;
		pDNode->pNext=NULL;
		pDNode->pPrevious=NULL;
	}
	else
	{
		cout<<"Loi cap phat o nho";
	}
	return pDNode;
}
void InsertFirst(DoubleList &list,SanPham *d)
{
	DNode *pDNode=CreateNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pDNode;
	}
	else
	{
		pDNode->pNext=list.pHead;
		list.pHead->pPrevious=pDNode;
		list.pHead=pDNode;
	}
}
void PrintList(DoubleList list)
{
	DNode *p=list.pHead;
	while(p!=NULL)
	{
		SanPham *d=p->data;
		cout<<d->ma<<" - "<<d->ten<<" - "<<d->gia<<"\n";
		p=p->pNext;
	}
}
void SapXepGiaGiamDan(DoubleList &list)
{
	for(DNode *p1=list.pHead;p1!=NULL;p1=p1->pNext)
	{
		for(DNode *p2=p1->pNext;p2!=NULL;p2=p2->pNext)
		{
			if(p1->data->gia<p2->data->gia)
			{
				SanPham *d1=p1->data;
				int ma1=d1->ma;
				char ten1[250];
				strcpy(ten1,d1->ten);
				double gia1=d1->gia;
				SanPham *d2=p2->data;
				
				p1->data->ma=d2->ma;
				strcpy(p1->data->ten,d2->ten);
				p1->data->gia=d2->gia;
				
				p2->data->ma=ma1;
				strcpy(p2->data->ten,ten1);
				p2->data->gia=gia1;
			}
		}
	}
}
DoubleList LocSanPhamTheoGia(DoubleList listGoc,double gia)
{
	DoubleList list;
	Initialize(list);
	DNode *p=listGoc.pHead;
	while(p!=NULL)
	{
		if(p->data->gia > gia)
		{
			SanPham *d=p->data;
			InsertFirst(list,d);
		}
		p=p->pNext;
	}
	return list;
}

int main(int argc, char** argv) {
	DoubleList list;
	Initialize(list);
	
	SanPham *sp1=new SanPham;
	sp1->ma=1;
	strcpy(sp1->ten,"coca");
	sp1->gia=15.5;
	InsertFirst(list,sp1);
	
	SanPham *sp2=new SanPham;
	sp2->ma=2;
	strcpy(sp2->ten,"pepsi");
	sp2->gia=13.5;
	InsertFirst(list,sp2);
	
	SanPham *sp3=new SanPham;
	sp3->ma=3;
	strcpy(sp3->ten,"redbull");
	sp3->gia=14.5;
	InsertFirst(list,sp3);
	
	PrintList(list);
	
	SapXepGiaGiamDan(list);
	cout<<"Danh sach sau khi sap Gia Giam Dan:\n";
	PrintList(list);
	
	DoubleList listGia=LocSanPhamTheoGia(list,15);
	cout<<"Dan sach san pham co gia >15:\n";
	PrintList(listGia);
	
	return 0;
}
