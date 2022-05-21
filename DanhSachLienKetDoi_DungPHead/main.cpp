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
		cout<<"Error allocated!";
	}
	return pDNode;
}
void PrintList(DoubleList list)
{
	DNode *pTmp=list.pHead;
	if(pTmp==NULL)
	{
		cout<<"The list is empty!";
		return;
	}
	while(pTmp!=NULL)
	{
		cout<<pTmp->data<<"\t";
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
void InsertFirst(DoubleList &list,int d)
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
void InsertMid(DoubleList &list,int pos,int d)
{
	if(pos<0||pos>=SizeOfList(list))
	{
		cout<<"Not valid position to insert";
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
		cout<<"The list is empty!";
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
		cout<<"Could not found number!";
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
	DNode *pTmp=list.pHead;
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
	for(DNode *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(DNode *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			if(pTmp->data>pTmp2->data)
			{
				int tmp=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=tmp;
			}
		}
	}
}
void FreeMemory(DoubleList &list)
{
	cout<<"\nStarting to delete...\n";
	while(list.pHead!=NULL)
	{
		DNode *pDel=list.pHead;
		list.pHead=list.pHead->pNext;
		pDel->pNext=NULL;
		pDel->pPrevious=NULL;
		cout<<pDel->data<<" is deleted\n";
		delete pDel;
		pDel=NULL;
	}
	cout<<"Deleting is completed\n";
}
int main(int argc, char** argv) {
	DoubleList list;
	Initialize(list);
	InsertFirst(list,5);
	InsertLast(list,4);
	InsertFirst(list,9);
	InsertFirst(list,8);
	InsertLast(list,3);
	InsertMid(list,2,1);
	InsertMid(list,5,10);
	InsertMid(list,0,30);
	//InsertMid(list,-1,6);
	cout<<"Danh sach Lien Ket doi la:\n";
	PrintList(list);
	RemoveNode(list,4);
	cout<<"\nDanh sach Lien Ket doi sau khi xoa so 4 la:\n";
	PrintList(list);
	RemoveNode(list,10);
	cout<<"\nDanh sach Lien Ket doi sau khi xoa so 10 la:\n";
	PrintList(list);
	RemoveNode(list,30);
	cout<<"\nDanh sach Lien Ket doi sau khi xoa so 30 la:\n";
	PrintList(list);
	DNode *result=SearchNode(list,30);
	if(result==NULL)
	{
		cout<<"\nKhong tim thay so 30";
	}
	else
	{
		cout<<"\nCo tim thay "<<result->data;
	}
	SortList(list);
	cout<<"\Danh sach lien ket doi sau khi Sort:\n";
	PrintList(list);
	FreeMemory(list);
	return 0;
}
