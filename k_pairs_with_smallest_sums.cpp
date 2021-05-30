#include <bits/stdc++.h>
using namespace std;

void kSmallestPair(vector<int> A, vector<int> B, int K)
{
	sort(A.begin(), A.end()); 
	sort(B.begin(), B.end());

	int n = A.size();

	priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,
				greater<pair<int, pair<int, int> > > > pq;

	set<pair<int, int> > my_set;

	pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));

	my_set.insert(make_pair(0, 0));

	for (int count = 0; count < K; count++) {

		pair<int, pair<int, int> > temp = pq.top();
		pq.pop();

		int i = temp.second.first;
		int j = temp.second.second;

		cout << "[" << A[i] << ", " << B[j] << "]"<< endl;

		if (i + 1 < A.size()) {
			int sum = A[i + 1] + B[j];
			pair<int, int> temp1 = make_pair(i + 1, j);

			if (my_set.find(temp1) == my_set.end()) {
				pq.push(make_pair(sum, temp1));
				my_set.insert(temp1);
			}
		}
		if (j + 1 < B.size()) {

			int sum = A[i] + B[j + 1];
			pair<int, int> temp1 = make_pair(i, j + 1);

			if (my_set.find(temp1) == my_set.end()) {
				pq.push(make_pair(sum, temp1));
				my_set.insert(temp1);
			}
		}
	}
}

int main()
{
	vector<int> A = { 2, 8, 12 };
	vector<int> B = { 4, 6, 8 };
	int K = 3;
	kSmallestPair(A, B, K);
	return 0;
}

