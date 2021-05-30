#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void merge(node *root1, node *root2)
{
    stack<node*> s1;node* cur1 = root1;
    stack<node*> s2;node* cur2 = root2;
    if(!root1){  
        inorder(root2);
        return;
    }
    if(!root2){
        inorder(root1);
        return;
    }
    while(cur1 != NULL || !s1.empty() || cur2 != NULL || !s2.empty())
    {
        if(cur1 != NULL || cur2 != NULL)
        {
            if(cur1 != NULL)
            {
                s1.push(cur1);
                cur1 = cur1->left;
            }
            if (cur2 != NULL)
            {
                s2.push(cur2);
                cur2 = cur2->left;
            }
        }
        else
        {
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    cur2 = s2.top();
                    s2.pop();
                    cur2->left = NULL;
                    inorder(cur2);
                }
                return;
            }
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    cur1 = s1.top();s1.pop();
                    cur1->left = NULL;
                    inorder(cur1);
                }
                return;
            }
            cur1 = s1.top();
            cur2 = s2.top();
            // print the smaller of the two and push the larger element into the corresponding stack
            if(cur1->data < cur2->data)
            {
                cout<<cur1->data<<" ";
                cur1 = cur1->right;
                s1.pop();
                cur2 = NULL;
            }
            else
            {
                cout<<cur2->data<<" ";
                cur2 = cur2->right;
                s2.pop();
                cur1 = NULL;
            }
        }
    }
}
int main()
{
    node *root1 = NULL, *root2 = NULL;
    
    root1 = newNode(3);
    root1->left = newNode(2);
    root1->right = newNode(5);
    
    root2 = newNode(4);
    root2->left = newNode(1);
    root2->right = newNode(6);
    
    merge(root1, root2);
    return 0;
}