#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct DNode
{
	int data;
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
	list.pHead=NULL;
	list.pTail=NULL;
}
DNode *CreateNode(int d)
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
		cout<<"Loi cap phat Bo Nho";
	}
	return pDNode;
}
void InsertLast(DoubleList &list,int d)
{
	DNode *pDNode=CreateNode(d);
	if(list.pHead==NULL)
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
	DNode *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong";
		return;
	}
	while(pTmp!=NULL)
	{
		cout<<pTmp->data;
		pTmp=pTmp->pNext;
	}
}
DoubleList TaoBigInteger(char *str)
{
	DoubleList list;
	Initialize(list);
	for(int i=0;i<strlen(str);i++)
	{
		char strTmp[1];
		strTmp[0]=str[i];
		int d=atoi(strTmp);
		InsertLast(list,d);
	}
	return list;
}
bool isPrime(int d)
{
	int dem=0;
	for(int i=1;i<=d;i++)
	{
		if(d%i==0)
		{
			dem++;
		}
	}
	return dem==2;
}
DoubleList LayDayNguyenTo(DoubleList listGoc)
{
	DoubleList list;
	Initialize(list);
	DNode *pTmp=listGoc.pHead;
	while(pTmp!=NULL)
	{
		int d=pTmp->data;
		bool kt=isPrime(d);
		if(kt==true)
		{
			InsertLast(list,d);
		}
		pTmp=pTmp->pNext;
	}
	return list;
}
void InsertFirst(DoubleList &list,int d)
{
	DNode *pDNode=CreateNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=list.pTail=pDNode;
	}
	else
	{
		pDNode->pNext=list.pHead;
		list.pHead->pPrevious=pDNode;
		list.pHead=pDNode;
	}
}
DoubleList Cong2So(DoubleList list1,DoubleList list2)
{
	DoubleList list3;
	Initialize(list3);
	DNode *tail1=list1.pTail;
	DNode *tail2=list2.pTail;
	int v2=0;
	while(tail1!=NULL || tail2!=NULL)
	{
		int v1=0;
		if(tail1!=NULL && tail2!=NULL)
		{
			v1=tail1->data+tail2->data;
		}
		else if(tail1!=NULL)
		{
			v1=tail1->data;	
		}
		else if(tail2!=NULL)
		{
			v1=tail2->data;
		}
		v1=v1+v2;
		if(v1>=10)
		{
			v2=v1/10;
			v1=v1%10;
		}
		else
		{
			v2=0;
		}
		InsertFirst(list3,v1);
		if(tail1!=NULL)
		{
			tail1=tail1->pPrevious;
		}
		if(tail2!=NULL)
		{
			tail2=tail2->pPrevious;
		}
	}
	if(v2!=0)
	{
		InsertFirst(list3,v2);
	}
	return list3;
}

int main(int argc, char** argv) {
	DoubleList list=TaoBigInteger("673546532145678987654145465789");
	cout<<"Big Integer:\n";
	PrintList(list);
	DoubleList listPrime=LayDayNguyenTo(list);
	cout<<"\nBig integer - prime:\n";
	PrintList(listPrime);
	
	DoubleList list1=TaoBigInteger("3254");
	DoubleList list2=TaoBigInteger("132");
	DoubleList list3=Cong2So(list1,list2);//457
	cout<<"\nlist1+list2=:\n";
	PrintList(list3);
	return 0;
}
