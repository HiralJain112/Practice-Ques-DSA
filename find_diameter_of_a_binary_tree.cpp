
#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


int height(struct node* node)
{
	if (node == NULL)
		return 0;

	return 1 + max(height(node->left), height(node->right));
}

int diameter(struct node* tree)
{
	if (tree == NULL)
		return 0;

	int lheight = height(tree->left);
	int rheight = height(tree->right);

	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	return max(lheight + rheight + 1,max(ldiameter, rdiameter));
}

int main()
{

	struct node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(9);
	root->left->left = newNode(1);
	root->left->right = newNode(2);
    root->right->left = newNode(7);
	root->right->right = newNode(10);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(8);

	cout <<diameter(root);

	return 0;
}

