#include <bits/stdc++.h>
using namespace std;

void dfstopo(vector<pair<int, int>> adjlist[], vector<bool> &visited, stack<int> &s, int i)
{
    visited[i] = true;
    for (auto x : adjlist[i])
    {
        if (!visited[x.first])
            dfstopo(adjlist, visited, s, x.first);
    }
    s.push(i);
}

void dfs(vector<pair<int, int>> adjlist[], int v, int src)
{
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfstopo(adjlist, visited, s, i);
    }
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto x : adjlist[node])
            {
                if(dist[x.first]> dist[node]+x.second){
                    dist[x.first] = dist[node]+x.second;
                }
            }
        }
    }
    for(auto x:dist){
        cout<<x<<" ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int e, v;
    cin >> e >> v;
    vector<pair<int, int>> adjlist[v];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
    }
    dfs(adjlist, v, 0);
    return 0;
}