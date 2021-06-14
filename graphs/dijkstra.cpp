#include <bits/stdc++.h>
using namespace std;
//TC = O((N+E)logN)
void dijkstra(vector<pair<int, int>> adjlist[], int v, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        pair<int, int> node = pq.top();
        pq.pop();
        for(auto x: adjlist[node.second]){
            if(dist[x.first] > dist[node.second]+x.second){
                dist[x.first] = dist[node.second]+x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    for(auto x: dist){
        cout<< x<<" ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int e, V;
    cin >> e >> V;
    vector<pair<int, int>> adjlist[V];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }
    dijkstra(adjlist, V, 0);
    return 0;
}