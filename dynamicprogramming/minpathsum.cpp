#include <bits/stdc++.h>
using namespace std;

// int mincostpath(vector<vector<int>>& grid, vector<vector<int>>& cost, int r, int c){
//     if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size())
//         return;
//     cost[r][c] = min(mincostpath(grid,cost,r+1,c) + grid[r][c] , mincostpath(grid,cost,r,c+1)+grid[r][c]);

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> cost(n, vector<int>(m, 0));
    cost[n - 1][m - 1] = grid[n - 1][m - 1];
    // int cost1 = mincostpath(grid, cost, n-1, m-1);
    // cout<<cost[n-1][m-1]<<endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i != n - 1 && j != m - 1)
                cost[i][j] = min(j + 1 < m ? cost[i][j + 1] : INT_MAX, i + 1 < n ? cost[i + 1][j] : INT_MAX) + grid[i][j];
        }
    }
    cout << cost[0][0] << endl;
    return 0;
}