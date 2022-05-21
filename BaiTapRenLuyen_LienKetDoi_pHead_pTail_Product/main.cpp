#include <iostream>
#include <string.h>
using namespace std;
struct Product
{
	int id;
	char name[250];
	float price;
};
struct DNode
{
	Product *data;
	DNode *pNext;
	DNode *pPrevious;	
};
struct DoubleList
{
	DNode *pHead;
	DNode *pTail;
};
void Initialize(DoubleList &list)
{
	list.pHead=list.pTail=NULL;
}
DNode *CreateNode(Product *d)
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
		cout<<"Loi cap phat O Nho";
	}
	return pDNode;
}
void InsertLast(DoubleList &list,Product *d)
{
	DNode *pDNode=CreateNode(d);
	if(list.pTail==NULL)
	{
		list.pHead=list.pTail=pDNode;
	}
	else
	{
		list.pTail->pNext=pDNode;
		pDNode->pPrevious=list.pTail;
		list.pTail=pDNode;
	}
}
void PrintList(DoubleList list)
{
	DNode * pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		Product *d=pTmp->data;
		cout<<d->id<<"\t"<<d->name<<"\t"<<d->price<<"\n";
		pTmp=pTmp->pNext;
	}
}
DoubleList Filter(DoubleList list,float a, float b)
{
	DoubleList listFilter;
	Initialize(listFilter);
	DNode *pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		Product *d=pTmp->data;
		if(d->price>=a && d->price<=b)
		{
			InsertLast(listFilter,d);
		}
		pTmp=pTmp->pNext;
	}
	return listFilter;
}
void SapXepGiaGiamDan(DoubleList &list)
{
	for(DNode *p1=list.pHead;p1!=NULL;p1=p1->pNext)
	{
		for(DNode *p2=p1->pNext;p2!=NULL;p2=p2->pNext)
		{
			if(p1->data->price<p2->data->price)
			{
				Product *d1=p1->data;
				int ma1=d1->id;
				char ten1[250];
				strcpy(ten1,d1->name);
				double gia1=d1->price;
				Product *d2=p2->data;
				
				p1->data->id=d2->id;
				strcpy(p1->data->name,d2->name);
				p1->data->price=d2->price;
				
				p2->data->id=ma1;
				strcpy(p2->data->name,ten1);
				p2->data->price=gia1;
			}
		}
	}
}
void RemoveNode(DoubleList &list, int id)
{
	DNode *pDel=list.pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong, sao ma xoa";
		return;
	}
	DNode *pPre=NULL;
	while(pDel!=NULL)
	{
		Product *p=pDel->data;
		if(p->id==id)
		{
			break;
		}
		pPre=pDel;
		pDel=pDel->pNext;
	}
	if(pDel==NULL)
	{
		cout<<"Ko tim thay de xoa";
	}
	else
	{
		if(pDel==list.pHead)
		{
			list.pHead=list.pHead->pNext;
			pDel->pNext=NULL;
			if(list.pHead!=NULL)
				list.pHead->pPrevious=NULL;
		}
		else if(pDel->pNext==NULL)
		{
			list.pTail=pPre;
			pDel->pPrevious=NULL;
			pPre->pNext=NULL;
		}
		else
		{
			pPre->pNext=pDel->pNext;
			pDel->pNext->pPrevious=pPre;
			pDel->pPrevious=NULL;
			pDel->pNext=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
}

int main(int argc, char** argv) {
	DoubleList list;
	Initialize(list);

	Product *p1=new Product;
	p1->id=1;
	strcpy(p1->name,"Coca");
	p1->price=150;
	InsertLast(list,p1);
	
	Product *p2=new Product;
	p2->id=2;
	strcpy(p2->name,"Pepsi");
	p2->price=200;
	InsertLast(list,p2);
	
	Product *p3=new Product;
	p3->id=3;
	strcpy(p3->name,"Sting");
	p3->price=80;
	InsertLast(list,p3);
	cout<<"Danh sach Product:\n";
	PrintList(list);
	
	DoubleList list2=Filter(list,150,200);
	cout<<"Danh sach Product co gia [150 200]:\n";
	PrintList(list2);
	
	SapXepGiaGiamDan(list);
	cout<<"Danh sach Product sau khi sap Gia Giam Dan:\n";
	PrintList(list);
	
	cout<<"Ban muon xoa Ma product nao:";
	int id;
	cin>>id;
	RemoveNode(list,id);
	cout<<"Danh sach Product sau khi xoa:\n";
	PrintList(list);
	return 0;
}
