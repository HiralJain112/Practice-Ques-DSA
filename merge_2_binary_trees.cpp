#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node *newNode(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void inorder(Node * node)
{
	if (!node)
		return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

Node *MergeBinaryTrees(Node * t1, Node * t2)
{
	if (!t1)
		return t2;
	if (!t2)
		return t1;
	t1->data += t2->data;
	t1->left = MergeBinaryTrees(t1->left, t2->left);
	t1->right = MergeBinaryTrees(t1->right, t2->right);
	return t1;
}

int main()
{
	Node *root1 = newNode(1);
	root1->left = newNode(6);
	root1->right = newNode(2);
	root1->left->left = newNode(5);

	Node *root2 = newNode(2);
	root2->left = newNode(1);
	root2->right = newNode(3);
	root2->left->right = newNode(4);
	root2->right->right = newNode(7);

	Node *root3 = MergeBinaryTrees(root1, root2);
	inorder(root3);
	return 0;
}
