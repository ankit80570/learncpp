#include<bits/stdc++.h>
using namespace std;

vector<int> allindex(vector<int>& nums, int idx, int x, int fsf){
    if(idx == nums.size())
        vector<int> indices(fsf,0);
        return indices;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int> nums = { 1, 2, 2, 5, 7, 8, 7};

vector<int> indices = allindex(nums, 0, 7, 0);
for(int i=0; i<indices.size(); i++){
    cout<<indices[i]<<" ";
}
return 0;
}