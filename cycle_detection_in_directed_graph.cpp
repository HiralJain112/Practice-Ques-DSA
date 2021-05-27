#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj,vector<bool> &visited,vector<int> &stack)
{
     stack[src] = true;
     if (!visited[src])
     {
         visited[src] = true;
         for(auto i: adj[src])
         {
            if (!visited[i] and iscycle(i,adj,visited,stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
         }
     }
    stack[src] = false;
    return false; 
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int>> adj(nodes);
    for(int i=0;i< edges; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    vector<int> stack(nodes,0);
    vector<bool> visited(nodes,0);
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i] and iscycle(i,adj,visited,stack))
        {
            cycle = true;
        }
        
    }
    
    if (cycle)
    {
        cout<<"Cycle is present";
    }
    else
    {
        cout<<"Cycle is not present";
    }
    
    return 0;
}