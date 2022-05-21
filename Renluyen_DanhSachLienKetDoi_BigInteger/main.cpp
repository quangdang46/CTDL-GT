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
};
void Initialize(DoubleList &list)
{
	list.pHead=NULL;
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
		list.pHead=pDNode;
	}
	else
	{
		DNode *pTmp=list.pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pDNode;
		pDNode->pPrevious=pTmp;
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

int main(int argc, char** argv) {
	DoubleList list=TaoBigInteger("673546532145678987654145465789");
	cout<<"Big Integer:\n";
	PrintList(list);
	DoubleList listPrime=LayDayNguyenTo(list);
	cout<<"\nBig integer - prime:\n";
	PrintList(listPrime);
	return 0;
}
