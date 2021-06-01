#include<bits/stdc++.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int n=0,m=0;
cin>>n>>m;
vector<vector<int>> grid(n,vector<int>(m));
for(int i=0; i<n; i++){
    for(int j=0; j<m ; j++){
        cin>>grid[i][j];
    }
}
vector<vector<int>> cost(n, vector<int>(m));
for(int i=0; i<m; i++){
    cost[i][m-1] = grid[i][m-1];
}
for(int j=m-2; j>=0; j--){
    for(int i=0; i<n; i++){
        if(i == 0){
            cost[i][j] = max(cost[i][j+1],cost[i+1][j+1]) + grid[i][j];
        }else if(i == n-1){
            cost[i][j] = max(cost[i][j+1],cost[i-1][j+1]) + grid[i][j];
        }else {
            cost[i][j] = max(cost[i][j+1],max(cost[i-1][j+1], cost[i+1][j+1])) + grid[i][j];
        }
    }
}
int max1 = INT_MIN;
for(int i=0; i<m; i++){
    max1 = max(max1,cost[i][0]); 
}
cout<<max1<<endl;
return 0;
}