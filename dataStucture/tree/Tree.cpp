#include"Tree.h"
#include<iostream>
#include"Node.h"
using namespace std;

Tree::Tree()
{
	m_pRoot = new Node();
}
Tree::~Tree()
{
	m_pRoot->DeleteNode();
}
Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);//从头结点搜索
}
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	Node *node = new Node();
	node->data = pNode->data;//指定Node各数据
	node->index = pNode->index;
	node->pParent = temp;
	if (direction == 0)
	{
		temp->pLchild = node;
	}
	if (direction == 1)
	{
		temp->pRchild = node;
	}
	return true;

}
bool Tree::DeleteNode(int nodeIndex, Node*pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}
	temp->DeleteNode();
	return true;
}

void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();

}