#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
void floodfill(vector<vector<int>>& maze, int r, int c, string osf, vector<vector<bool>>& visited){
    if(r<0 || c<0 || r>=maze.size() || c>=maze[0].size() || visited[r][c] ||maze[r][c] == 1 ){//
        return;
    }
    if(r == maze.size()-1 && c == maze[0].size()-1){
        cout<<osf<<endl;
        return;
    }
    visited[r][c]= true;
    floodfill(maze, r-1,c,osf+"t",visited);
    floodfill(maze, r,c-1,osf+"l",visited);
    floodfill(maze, r+1,c,osf+"d",visited);
    floodfill(maze, r,c+1,osf+"r",visited);
    visited[r][c] = false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
cin>>n>>m;
// n=3;
// m=3;
vector<vector<int>> vec( n , vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>vec[i][j];
        }

    }
vector<vector<bool>> visited( n , vector<bool> (m, false));
floodfill(vec, 0,0,"",visited);
return 0;
}