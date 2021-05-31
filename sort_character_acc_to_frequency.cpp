#include <bits/stdc++.h>
using namespace std;

int countFreq(string str, char ch)
{
	int count = 0;

	for (int i = 0; i < str.length(); i++)
		if (str[i] == ch)
			++count;

	return count;
}
bool compare( const pair<int,char>& x, const pair<int, char>& y )
{

    return (x.first < y.first);

}
void sort_characters(string str)
{
	int n = str.length();

	vector<pair<int, char> > v;

	for (int i = 0; i < n; i++) {

		v.push_back(make_pair(countFreq(str, str[i]),str[i]));
	}
	sort(v.rbegin(),v.rend(),compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].second;
}

int main()
{
	string str = "free";

	sort_characters(str);

	return 0;
}
