#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adjlist[], vector<bool> &visited, int v)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                cout << q.front() << " ";
                int n = q.front();
                q.pop();
                for (auto x : adjlist[n])
                {
                    if (!visited[x])
                    {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }
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
    vector<bool> visited(v, false);
    bfs(adjlist, visited, v);
    return 0;
}