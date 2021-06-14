// Shortest Path in Undirected Graph with Unit Weights
#include <bits/stdc++.h>
using namespace std;

void dist(vector<int> adjlist[], int v, int src)
{
    vector<int> dists(v, INT_MAX);
    queue<int> q;
    dists[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto x : adjlist[node])
        {
            if (1 + dists[node] < dists[x])
            {
                dists[x] = 1 + dists[node];
                q.push(x);
            }
        }
    }
    for(auto x: dists){
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
    vector<int> adjlist[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dist(adjlist, v, 0);

    return 0;
}