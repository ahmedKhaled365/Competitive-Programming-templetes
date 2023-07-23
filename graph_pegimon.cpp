const int N = 1e5;
vector<int> graph[N];
bool visited[N];

void dfs(int pos){
    visited[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++)
    {
        int node = graph[pos][i];
        if (!visited[node])
        {
            dfs(node);
        }
        
    }
    
}

// check if acyclic in directed graph
bool ancestor[N];
bool dfs(int pos){
    visited[pos] = true;
    ancestor[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++)
    {
        int node = graph[pos][i];
        if (visited[node] && ancestor[node])
        {
            return true;
        }
        else if (!visited[node] && dfs(node))
        {
            return true;
        }
    }
    ancestor[pos] = false;
    return false;
}

// check if acyclic in undirected graph
bool dfs(int pos, int parent){
    visited[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++)
    {
        int node = graph[pos][i];
        if (visited[node] && node != parent)
        {
            return true;
        }
        if (!visited[node] && dfs(node, pos))
        {
            return true;
        }
        
    }
    return false;
}
