#include <iostream>
using namespace std;
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
			parent->pLeft=node;
		else
			parent->pRight=node;
	}
}
void PreOrder_NLR(BTree root)
{
	if(root!=NULL)
	{
		cout<<root->Value<<"\t";
		PreOrder_NLR(root->pLeft);
		PreOrder_NLR(root->pRight);
	}
}
void PostOrder_LRN(BTree root)
{
	if(root!=NULL)
	{
		PostOrder_LRN(root->pLeft);
		PostOrder_LRN(root->pRight);
		cout<<root->Value<<"\t";
	}
}
void Inorder_LNR(BTree root)
{
	if(root!=NULL)
	{
		Inorder_LNR(root->pLeft);
		cout<<root->Value<<"\t";
		Inorder_LNR(root->pRight);
	}
}
int CountNode(BTree root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return 1+CountNode(root->pLeft)+CountNode(root->pRight);
	}
}
int CountLeaf(BTree root)
{
	if(root!=NULL)
	{
		if(root->pLeft==NULL && root->pRight==NULL)
		{
			return 1;
		}
		else
		{
			return CountLeaf(root->pLeft)+CountLeaf(root->pRight);
		}
	}
	else
	{
		return 0;
	}
}
int max(int a,int b)
{
	return a>b?a:b;
}
int Height(BTree root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return 1+max(Height(root->pLeft),Height(root->pRight));
	}
}
TNode* Search(BTree root,int v)
{
	if(root==NULL || root->Value==v)
	{
		return root;
	}
	else
	{
		if(v<root->Value)
		{
			return Search(root->pLeft,v);
		}
		else
		{
			return Search(root->pRight,v);
		}
	}
}
void RemoveNode(BTree &root,int v)
{
	if(root==NULL)
	{
		cout<<"Cay Rong!";
		return;
	}
	TNode *pParent=NULL;
	TNode *pDel=NULL;
	TNode *pTmp=root;
	while(pTmp!=NULL)
	{
		pParent=pTmp;
		if(pTmp->Value>v)
		{
			pTmp=pTmp->pLeft;
		}
		else if(pTmp->Value<v)
		{
			pTmp=pTmp->pRight;
		}
		if(pTmp->Value==v)
		{
			pDel=pTmp;
			break;
		}
	}
	if(pDel==NULL)
	{
		cout<<"Ko thay";
		return;
	}
	if(pDel->pLeft==NULL&&pDel->pRight==NULL)
	{
		if(pParent->Value>pDel->Value)
			pParent->pLeft=NULL;
		else
			pParent->pRight=NULL;
		delete pDel;
		pDel=NULL;	
	}
	else if(pDel->pLeft!=NULL && pDel->pRight==NULL)
	{
		if(pParent->Value>pDel->Value)
			pParent->pLeft=pDel->pLeft;
		else
			pParent->pRight=pDel->pLeft;
		pDel->pLeft=NULL;
		delete pDel;
		pDel=NULL;
	}
	else if(pDel->pLeft==NULL&& pDel->pRight!=NULL)
	{
		if(pParent->Value>pDel->Value)
		{
			pParent->pLeft=pDel->pRight;
			pDel->pRight=NULL;
		}
		else
		{
			pParent->pRight=pDel->pRight;
			pDel->pRight=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
	else
	{
		TNode *pMinOfRight=pDel->pRight;
		TNode *pParentMinOfRight=NULL;
		while(pMinOfRight->pLeft!=NULL)
		{
			pParentMinOfRight=pMinOfRight;
			pMinOfRight=pMinOfRight->pLeft;
		}
		pDel->Value=pMinOfRight->Value;
		if(pParentMinOfRight==NULL)
		{
			pDel->pRight=NULL;
		}
		else if(pParentMinOfRight->Value>pMinOfRight->Value)
		{
			pParentMinOfRight->pLeft=pMinOfRight->pRight;
		}
		delete pMinOfRight;
		pMinOfRight=NULL;
	}
}

int main(int argc, char** argv) {
	BTree root=NULL;
	InsertNode(root,10);
	InsertNode(root,20);
	InsertNode(root,5);
	InsertNode(root,8);
	InsertNode(root,15);
	InsertNode(root,30);
	InsertNode(root,6);
	cout<<"\nDuyet Cay Theo PreOrder(NLR):\n";
	PreOrder_NLR(root);
	cout<<"\nDuyet Cay Theo PostOrder(LRN):\n";
	PostOrder_LRN(root);
	cout<<"\nDuyet Cay Theo Inorder(LNR):\n";
	Inorder_LNR(root);
	int c1=CountNode(root);
	cout<<"\nSo Node tren Cay="<<c1<<"\n";
	int c2=CountLeaf(root);
	cout<<"\nSo Node la tran Cay="<<c2<<"\n";
	int h=Height(root);
	cout<<"Chieu Cao cua Cay="<<h<<"\n";
	int v;
	cout<<"Ban muon tim so nao:";
	cin>>v;
	TNode *node=Search(root,v);
	if(node==NULL)
	{
		cout<<"Ko tim thay "<<v;
	} 
	else
	{
		cout<<"Tim thay v="<<node->Value;
	}
	RemoveNode(root,6);
	cout<<"\nDuyet Cay Theo Inorder(LNR) sau khi xoa nut la 6:\n";
	Inorder_LNR(root);
	RemoveNode(root,20);
	cout<<"\nDuyet Cay Theo Inorder(LNR) sau khi xoa nut la 20:\n";
	Inorder_LNR(root);
	return 0;
}
