#ifndef TREE_H_
#define TREE_H_
#include"Node.h"
class Tree
{
public:
	Tree();
	~Tree();
	Node *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, Node *pNode);
	bool DeleteNode(int nodeIndex, Node*pNode);
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
private:
	Node *m_pRoot;
};
#endif
