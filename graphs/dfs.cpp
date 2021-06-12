#include <bits/stdc++.h>
using namespace std;

void dfsutil(int i, vector<int> adjlist[], vector<bool> &visited, int v){
    cout<< i << " ";
    visited[i] = true;
    for(auto x: adjlist[i]){
        if(!visited[x]){
            dfsutil(x, adjlist, visited, v);
        }
    }
}
void recdfs(vector<int> adjlist[], vector<bool> &visited, int v){
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfsutil(i, adjlist, visited, v);
        }
    }
}

void itrdfs(vector<int> adjlist[], vector<bool> &visited, int v)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while (!s.empty())
            {
                int n = s.top();
                s.pop();
                cout << n << " ";
                for (auto x : adjlist[n])
                {
                    if (!visited[x])
                    {
                        s.push(x);
                        visited[x] = true;
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
    itrdfs(adjlist, visited, v);
    cout<<endl;
     vector<bool> visited1(v, false);
    recdfs(adjlist, visited1, v);
    return 0;
}