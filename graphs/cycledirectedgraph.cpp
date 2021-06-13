#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjlist[], int u, int v)
{
    adjlist[u].push_back(v);
}
bool dfsutil(vector<int> adjlist[], vector<bool> &visited, vector<bool> &dfs, int i)
{
    visited[i] = true;
    dfs[i] = true;
    for (auto x : adjlist[i])
    {
        if (!visited[x])
        {
            if (dfsutil(adjlist, visited, dfs, x))
                return true;
        }
        else if (dfs[x])
        {
            return true;
        }
    }
    dfs[i] = false;
    return false;
}
bool cycle(vector<int> adjlist[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> dfs(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfsutil(adjlist, visited, dfs, i))
                return true;
        }
    }
    return false;
}
bool cyclebfs(vector<int> adjlist[], int v){
    queue<int> q;
    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++){
        for(auto x: adjlist[i]){
            indegree[x]++;
        }
    }
    int cnt=0;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto x: adjlist[node]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    if(cnt == v) return false;
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, e;
    cin >> e >> v;

    vector<int> adjlist[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adjlist, u, v);
    }
    cout << cyclebfs(adjlist, v);
    return 0;
}