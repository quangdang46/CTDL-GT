#include <iostream>
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
	list.pHead=list.pTail=NULL;
}
void PrintList(DoubleList list)
{
	DNode *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach Rong!";
		return;
	}
	while(pTmp!=NULL)
	{
		cout<<pTmp->data<<"  ";
		pTmp=pTmp->pNext;
	}
}
int SizeOfList(DoubleList list)
{
	DNode *pTmp=list.pHead;
	int nSize=0;
	while(pTmp!=NULL)
	{
		pTmp=pTmp->pNext;
		nSize++;
	}
	return nSize;
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
		cout<<"Cap phat o nho that bai";
	}
	return pDNode;
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
void InsertLast(DoubleList &list,int d)
{
	DNode * pDNode=CreateNode(d);
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
void InsertMid(DoubleList &list,int pos,int d)
{
	if(pos<0||pos>=SizeOfList(list))
	{
		cout<<"Nhap sai vi tri";
		return;
	}
	if(pos==0)
	{
		InsertFirst(list,d);		
	}
	else if(pos==SizeOfList(list)-1)
	{
		InsertLast(list,d);
	}
	else
	{
		DNode *pDNode=CreateNode(d);
		DNode *pIns=list.pHead;
		DNode *pPre=NULL;
		int i=0;
		while(pIns!=NULL)
		{
			if(i==pos)
				break;
			pPre=pIns;
			pIns=pIns->pNext;
			i++;
		}
		pDNode->pNext=pIns;
		pDNode->pPrevious=pPre;
		pPre->pNext=pDNode;
		pIns->pPrevious=pDNode;
	}
}
void RemoveNode(DoubleList &list,int d)
{
	DNode *pDel=list.pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong";
		return;
	}
	DNode *pPre=NULL;
	while(pDel!=NULL)
	{
		if(pDel->data==d)
		{
			break;
		}
		pPre=pDel;
		pDel=pDel->pNext;
	}
	if(pDel==NULL)
	{
		cout<<"Tim ko thay so "<<d<<" de xoa";
	}
	else
	{
		if(pDel==list.pHead)
		{
			list.pHead=list.pHead->pNext;
			pDel->pNext=NULL;
			if(list.pHead!=NULL)
			{
				list.pHead->pPrevious=NULL;
			}
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
DNode * SearchNode(DoubleList list,int d)
{
	DNode * pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		if(pTmp->data==d)
		{
			break;
		}
		pTmp=pTmp->pNext;
	}
	return pTmp;
}
void SortList(DoubleList &list)
{
	for(DNode *p1=list.pHead;p1!=NULL;p1=p1->pNext)
	{
		for(DNode *p2=p1->pNext;p2!=NULL;p2=p2->pNext)
		{
			if(p1->data>p2->data)
			{
				int tmp=p1->data;
				p1->data=p2->data;
				p2->data=tmp;
			}
		}
	}
}

int main(int argc, char** argv) {
	DoubleList list;
	Initialize(list);
	InsertFirst(list,5);
	InsertLast(list,2);
	InsertFirst(list,9);
	InsertLast(list,7);
	InsertFirst(list,8);
	cout<<"Danh sach lien ket doi:\n";
	PrintList(list);
	InsertMid(list,1,100);
	cout<<"\nDanh sach lien ket sau khi chen:\n";
	PrintList(list);
	InsertMid(list,5,113);
	cout<<"\nDanh sach lien ket sau khi chen:\n";
	PrintList(list);
	InsertMid(list,0,114);
	cout<<"\nDanh sach lien ket sau khi chen:\n";
	PrintList(list);
	RemoveNode(list,7);
	cout<<"\nDanh sach lien ket sau khi xoa so 7:\n";
	PrintList(list);
	RemoveNode(list,114);
	cout<<"\nDanh sach lien ket sau khi xoa so 114:\n";
	PrintList(list);
	RemoveNode(list,113);
	cout<<"\nDanh sach lien ket sau khi xoa so 113:\n";
	PrintList(list);
	cout<<"\nBan muon tim so nao:";
	int x;
	cin>>x;
	DNode *ret=SearchNode(list,x);
	if(ret!=NULL)
	{
		cout<<"Tim thay "<<ret->data;
	}
	else
	{
		cout<<"Ko tim thay "<<x;
	}
	SortList(list);
	cout<<"Danh sach sau khi sap xep:\n";
	PrintList(list);
	return 0;
}
