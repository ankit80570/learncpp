#include<bits/stdc++.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int n=0;
cin>>n;
vector<int> nums(n);
for(int i=0; i<n; i++)
    cin>>nums[i];
int k=0;
cin>>k;
vector<vector<bool>> dp(n+1,vector<bool>(k+1));

for(int i=0; i<dp.size(); i++)
{
    for (int j = 0; j < dp[0].size(); j++)
    {
        if(i==0&&j==0){
            dp[i][j] = true;
        }else if(i==0){
            dp[i][j] = false;
        }else if(j==0){
            dp[i][j] = true;
        }else {
            if(dp[i-1][j] == true)
                dp[i][j] = true;
            else{
                if(j>=nums[i-1] && dp[i-1][j-nums[i-1]] == true)
                    dp[i][j] = true;
            }
        }
    }
    
}
cout<<dp[n][k];
return 0;
}