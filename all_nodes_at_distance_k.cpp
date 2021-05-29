#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

node *newnode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void kdistanceNodeDown(node *root, int k)
{
	if (root == NULL || k < 0) 
        return;

	if (k==0)
	{
		cout << root->data << endl;
		return;
	}

	kdistanceNodeDown(root->left, k-1);
	kdistanceNodeDown(root->right, k-1);
}

int kdistanceNode(node* root, node* target , int k)
{
	if (root == NULL) 
        return -1;

	if (root == target)
	{
		kdistanceNodeDown(root, k);
		return 0;
	}

	int distanceleft = kdistanceNode(root->left, target, k);

	if (distanceleft != -1)
	{
		if (distanceleft + 1 == k)
			cout << root->data << endl;

		else
			kdistanceNodeDown(root->right, k - distanceleft-2);

		return 1 + distanceleft;
	}

	
	int distanceRight = kdistanceNode(root->right, target, k);
	if (distanceRight != -1)
	{
		if (distanceRight + 1 == k)
			cout << root->data << endl;
		else
			kdistanceNodeDown(root->left, k-distanceRight-2);
		return 1 + distanceRight;
	}

	return -1;
}

int main()
{
	node * root = newnode(5);
	root->left = newnode(6);
	root->right = newnode(3);
	root->left->left = newnode(1);
	root->left->right = newnode(7);
    root->right->left = newnode(9);
	root->right->right = newnode(4);
	root->left->right->left = newnode(2);
	root->left->right->right = newnode(0);
	node * target = root->left;
	kdistanceNode(root, target, 2);
	return 0;
}
