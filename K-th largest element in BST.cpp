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
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return node; 
}
void kthLargestUntil(Node *root, int k, int &count)
{
    if (root == NULL || count >= k)
        return;
 
    kthLargestUntil(root->right, k, count);
 
    count++;
    if (count == k)
    {
        cout << root->data << endl;
        return;
    }
    kthLargestUntil(root->left, k, count);
}

void kthLargest(Node *root, int k)
{
    int count = 0;
    kthLargestUntil(root, k, count);
}

int main()
{
    int k;
    cin>>k;
    Node* root = newNode(10);
    root -> left = newNode(4); 
    root -> right = newNode(20);
    root -> left -> left = newNode(2);
    root -> right -> left = newNode(15);  
    root -> right -> right = newNode(40);  
    
    kthLargest(root,k);
    return 0;
}