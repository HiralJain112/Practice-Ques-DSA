
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

void flattenBinaryTree(struct Node* root)
{
	
	if (root == NULL || root->left == NULL &&
						root->right == NULL) {
		return;
	}

	if (root->left != NULL) {

		flattenBinaryTree(root->left);

		struct Node* tmpRight = root->right;
		root->right = root->left;
		root->left = NULL;

		struct Node* t = root->right;
		while (t->right != NULL) {
			t = t->right;
		}

		t->right = tmpRight;
	}
	flattenBinaryTree(root->right);
}

void inorder(struct Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

int main()
{
	Node* root = newNode(4);
	root->left = newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(6);
	root->left->right = newNode(7);
	root->right->right = newNode(9);

	flattenBinaryTree(root);
	inorder(root);
	return 0;
}
