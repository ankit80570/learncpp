#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjlist[], int u, int v)
{
    adjlist[u].push_back(v);
}

void dfsutil(vector<int> adjlist[], vector<bool> &visited, stack<int> &s, int i)
{
    visited[i] = true;
    for (auto x : adjlist[i])
    {
        if (!visited[x])
        {
            dfsutil(adjlist, visited, s, x);
        }
    }
    s.push(i);
}

vector<int> toposort(vector<int> adjlist[], int v)
{
    vector<bool> visited(v, false);
    stack<int> s;
    vector<int> result;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsutil(adjlist, visited, s, i);
        }
    }
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, e;
    cin >> e >> N;

    vector<int> adjlist[N];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adjlist, u, v);
    }
    vector<int> result;
    result = toposort(adjlist, N);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}