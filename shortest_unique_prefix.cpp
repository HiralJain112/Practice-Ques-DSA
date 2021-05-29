#include<bits/stdc++.h>
using namespace std;

#define MAX 256

#define MAX_WORD_LEN 50

struct trieNode
{
	struct trieNode *child[MAX];
	int freq;
};

struct trieNode *newTrieNode(void)
{
	struct trieNode *newNode = new trieNode;
	newNode->freq = 1;
	for (int i = 0; i<MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}

void insert(struct trieNode *root, string str)
{
	struct trieNode *pCrawl = root;

	for (int level = 0; level< str.length(); level++)
	{
		int index = str[level];

		if (!pCrawl->child[index])
			pCrawl->child[index] = newTrieNode();
		else
		(pCrawl->child[index]->freq)++;

		pCrawl = pCrawl->child[index];
	}
}

void findPrefixesUntil(struct trieNode *root, char prefix[],
					int idx)
{
	if (root == NULL)
	return;

	if (root->freq == 1)
	{
	prefix[idx] = '\0';
	cout << prefix << " ";
	return;
	}

	for (int i=0; i<MAX; i++)
	{
	if (root->child[i] != NULL)
	{
		prefix[idx] = i;
		findPrefixesUntil(root->child[i], prefix, idx+1);
	}
	}
}

void findPrefixes(string arr[], int n)
{
	struct trieNode *root = newTrieNode();
	root->freq = 0;
	for (int i = 0; i<n; i++)
		insert(root, arr[i]);

	char prefix[MAX_WORD_LEN];

	findPrefixesUntil(root, prefix, 0);
}

int main()
{
	string arr[] = {"alphabet", "carpet", "cartoon", "carrot","alpine"};
	int n = sizeof(arr)/sizeof(arr[0]);
	findPrefixes(arr, n);

	return 0;
}
