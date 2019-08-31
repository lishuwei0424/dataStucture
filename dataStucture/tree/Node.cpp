#include "Node.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//构造函数
Node::Node()
{	
	index= 0;
	data = 0;

	pLchild = NULL;
	pRchild = NULL;
	pParent = NULL;
}

//搜索节点
Node *Node::SearchNode(int nodeIndex)
{
	if (this->index == nodeIndex)
	{
		return  this;
	}
    
	Node *temp = NULL;
	if (this->pLchild != NULL)
	{
		if (this->pLchild->index == nodeIndex)
		{
			return this->pLchild;
		}
		else
		{
			temp = this->pLchild->SearchNode(nodeIndex);

			if (temp != NULL)
			{
				return temp;
			}
		}

	}

	if (this->pRchild != NULL)
	{
		if (this->pLchild->index == nodeIndex)
		{
			return this->pLchild;
		}
		else
		{
			temp = this->pRchild->SearchNode(nodeIndex);

			if (temp != NULL)
			{
				return temp;
			}
		}
		
	}

	return  temp;
}


//删除节点
void Node::DeleteNode()
{
	if (this->pLchild != NULL)
	{
		this->pLchild->DeleteNode();
	}

	if (this->pRchild != NULL)
	{
		this->pRchild->DeleteNode();
	}

	if (this->pParent != NULL)
	{
		if (this->pParent->pLchild == this)
		{
			this->pParent->pLchild = NULL;
		}
		if (this->pParent->pRchild == this)
		{
			this->pParent->pRchild = NULL;
		}
	}

	delete this;
}

//前序遍历
void Node::PreorderTraversal()
{
	cout << this->data << endl;

	if (this->pLchild != NULL)
	{
		this->pLchild->PreorderTraversal();
	}


	if (this->pRchild != NULL)
	{
		this->pRchild->PreorderTraversal();

	}
}

//中序遍历
void Node::InorderTraversal()
{
	cout << this->data << endl;

	if (this->pLchild != NULL)
	{
		this->pLchild->InorderTraversal();
	}

	if (this->pRchild != NULL)
	{
		this->pRchild->InorderTraversal();
	}
}

//后序遍历
void Node::PostorderTraversal()
{
	if (this->pLchild!=NULL)
	{
		this->pLchild->PostorderTraversal();
	}


	if (this->pRchild != NULL)
	{
		this->pRchild->PostorderTraversal();
	}

	cout << this->data << endl;

}

