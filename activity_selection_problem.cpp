#include<bits/stdc++.h>
using namespace std;

void activity_selection_problem(vector<vector<int>> v, int n)
{
    int end = v[0][1];
    cout<<"0 ";
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] >= end)
        {
            cout<<i<<" ";
            end = v[i][1];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    activity_selection_problem(v,n);

    return 0;
}