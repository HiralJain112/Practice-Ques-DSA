#include <bits/stdc++.h>
using namespace std;
	
struct node {
	int data;
	node* left;
	node* right;
};
node *newNode(int data)
{
	node *new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
void inorder(node* curr, node*& prev, int& result)
{
	if (curr == NULL)
		return;
	
	inorder(curr->left, prev, result);
	
	if (prev != NULL)
		result = min(curr->data - prev->data, result);
	prev = curr;

	inorder(curr->right, prev, result);
}

int minAbsoluteDifference(node* root)
{
	node* prev = NULL;
	int result = INT_MAX;
	inorder(root, prev, result);
	return result;
}
int main()
{
	node* root = newNode(7);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->right->left = newNode(8);
	root->right->right = newNode(12);
	
	cout << minAbsoluteDifference(root);
	
	return 0;
}
