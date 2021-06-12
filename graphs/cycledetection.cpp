#include <bits/stdc++.h>
using namespace std;
// Cycle bfs not working
bool cyclebfs(vector<int> adj[], vector<bool> &visited)
{
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]){
            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i] = true;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto x: adj[parent]){
                    if(!visited[x])
                    {   
                        q.push({x,node});
                        visited[x] = true;
                    }
                    else if(x!=parent)
                        return true;
                }

            }
        }
    }
    return false;
}

bool dfsutil(vector<int> adj[], vector<bool> &visited, int i, int parent){
    visited[i] = true;
    for(auto x:adj[i]){
        if(!visited[x]){
            if(dfsutil(adj,visited,x,i)) return true;
        }else if(x != parent) return true;
    }
    return false;
}

bool cycledfs(vector<int> adj[], vector<bool> &visited){
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]){
            if(dfsutil(adj,visited, i, -1)) return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int e, v;
    cin >> e >> v;
    vector<int> adjlist[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<bool> visited(v, false);
    cout<<cyclebfs(adjlist, visited);
    return 0;
}