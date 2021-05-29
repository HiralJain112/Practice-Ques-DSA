#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

void swap( int* a, int* b )
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return(new_node);
}

void recover_BST_until( struct node* root, struct node** first,struct node** middle,
                     struct node** last,struct node** prev )
{
	if( root )
	{
		recover_BST_until( root->left, first, middle, last, prev );

		if (*prev && root->data < (*prev)->data)
		{
			if ( !*first )
			{
				*first = *prev;
				*middle = root;
			}

			else
				*last = root;
		}

		*prev = root;
		recover_BST_until( root->right, first, middle, last, prev );
	}
}

void recoverBST( struct node* root )
{
	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;

	recover_BST_until( root, &first, &middle, &last, &prev );

	if( first && last )
		swap( &(first->data), &(last->data) );
	else if( first && middle )
		swap( &(first->data), &(middle->data) );

}

void inorder(struct node* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

int main()
{
	struct node *root = newNode(10);
	root->left	 = newNode(5);
	root->right	 = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(20);

	recoverBST(root);

	inorder(root);

	return 0;
}
