#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}
Node* sortedArrayToBST(int arr[],
						int start, int end)
{
	if (start > end)
	return NULL;

	int mid = (start + end)/2;
	Node *root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start,
									mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}
void inOrder(Node* node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	cout << node->data << " ";
    inOrder(node->right);
}
void postOrder(Node* node)
{
	if (node == NULL)
		return;
	postOrder(node->left);
	postOrder(node->right);
    cout << node->data << " ";
}
int main()
{
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	Node *root = sortedArrayToBST(arr, 0, n-1);
	preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
	return 0;
}

