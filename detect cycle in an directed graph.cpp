bool isCyclicfn(vector<int> adj[], vector<bool> visited, int curr)
	{
	    if(visited[curr])
	    {
	        return true;
	    }
	    visited[curr] = true;
	    bool flag = false;
	    for(int i = 0; i < adj[curr].size(); i++)
	    {
	        flag = isCyclicfn(adj, visited, adj[curr][i]);
	        if(flag)
	        {
	            return true;
	        }
	    }
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    bool flag = false;
	    for(int i = 0; i<V; i++)
	    {
	        visited[i] = true;
	        for(int j = 0; j < adj[i].size() ; ++j)
	        {
	            flag = isCyclicfn(adj, visited, adj[i][j]);
	            if(flag)
	            {
	                return true;
	            }
	        }
	        visited[i] = false;
	    }     
	    return false;
	} 
