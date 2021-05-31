#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	struct Node* new_node = new Node();

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

struct compare {
	bool operator()(
		struct Node* a, struct Node* b)
	{
		return a->data > b->data;
	}
};

struct Node* mergeKSortedLists(
	struct Node* arr[], int k)
{
	priority_queue<Node*, vector<Node*>, compare> pq;

	for (int i = 0; i < k; i++)
		if (arr[i] != NULL)
			pq.push(arr[i]);
	
	if (pq.empty())
		return NULL;

	struct Node *result = newNode(0);
	struct Node *temp = result;

	while (!pq.empty()) {

		struct Node* curr = pq.top();
		pq.pop();
		temp->next = curr;
		temp = temp->next;
	
		if (curr->next != NULL)
			pq.push(curr->next);
	}

	return result->next;
}

void Display(struct Node* temp)
{
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	int k = 3; 
	int n = 3; 

	Node* arr[k];

	arr[0] = newNode(1);
	arr[0]->next = newNode(3);
	arr[0]->next->next = newNode(7);

	arr[1] = newNode(2);
	arr[1]->next = newNode(4);
	arr[1]->next->next = newNode(8);

	arr[2] = newNode(9);
	arr[2]->next = newNode(10);
	arr[2]->next->next = newNode(11);

	struct Node* head = mergeKSortedLists(arr, k);

	Display(head);

	return 0;
}
