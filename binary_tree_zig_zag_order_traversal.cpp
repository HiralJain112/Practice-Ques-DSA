#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
};
vector<int> zigZagTraversal(Node* root)
{
	deque<Node*> q;
	vector<int> v;
	q.push_back(root);
	v.push_back(root->data);
	Node* temp;

	// set initial level as 1, because root is
	// already been taken care of.
	int level = 1;
				
	while (!q.empty()) {
		int n = q.size();

		for (int i = 0; i < n; i++) {

			// popping mechanism
			if (level % 2 == 0) {
				temp = q.back();
				q.pop_back();
			}
			else {
				temp = q.front();
				q.pop_front();
			}

			// pushing mechanism
			if (level % 2 != 0) {

				if (temp->right) {
					q.push_back(temp->right);
					v.push_back(temp->right->data);
				}
				if (temp->left) {
					q.push_back(temp->left);
					v.push_back(temp->left->data);
				}
			}
			else if (level % 2 == 0) {

				if (temp->left) {
					q.push_front(temp->left);
					v.push_back(temp->left->data);
				}
				if (temp->right) {
					q.push_front(temp->right);
					v.push_back(temp->right->data);
				}
			}
		}
		level++; 
	}
	return v;
}
struct Node* newNode(int data)
{
	struct Node* node = new struct Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{
    vector<int> v;
    struct Node* root = newNode(5);
    root -> left = newNode(8); 
    root -> right = newNode(2);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(4);
    v = zigZagTraversal(root);
    for (int i = 0; i < v.size();i++) 
    { 
		cout << v[i] << " ";
	}
    
    return 0;
}
