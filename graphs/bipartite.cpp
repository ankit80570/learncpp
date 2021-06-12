#include <bits/stdc++.h>
using namespace std;

bool bipartitebfs(vector<int> adj[], int v)
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto x : adj[node])
                {
                    if (color[x] == -1)
                    {
                        color[x] = 1 - color[node];
                        q.push(x);
                    }
                    else if (color[x] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
}

bool dfsutil(vector<int> adj[], vector<int> &color, int i){
    for(auto x: adj[i]){
        if(color[x] == -1){
            color[x] = 1-color[i];
            if(!dfsutil(adj,color,x)) return false;
        } else if(color[x] == color[i]){
            return false;
        }
    }
    return true;
}
bool bipartitedfs(vector<int> adj[], int v)
{
    vector<int> color(v, -1);
    for(int i = 0; i<v; i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!dfsutil(adj,color,i)) return false;
        }
    }
    return true;
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
    cout << bipartitedfs(adjlist, v);

    return 0;
}