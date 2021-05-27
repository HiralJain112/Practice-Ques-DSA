#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int key)
    {
	   data = key;
	   left = NULL;
       right = NULL;
    }
};
int minimumDepth(Node *root, int level)
{
		
	if (root == NULL)
			return level;
	level++;

	return min(minimumDepth(root->left, level),minimumDepth(root->right, level));
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
	root->right = new Node(15);
    root->right->left = new Node(11);
    root->right->right = new Node(6);
    
    cout<<minimumDepth(root , 0);
    
    return 0;
}