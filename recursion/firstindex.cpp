#include<bits/stdc++.h>
using namespace std;

int firstindex(vector<int>& nums, int idx, int x){
    if(idx == nums.size()){
        return -1;
    }
    if(nums[idx] == x)
        return idx;
    else return firstindex(nums, idx+1, x);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int> nums = { 1, 2, 2, 5, 7, 8, 7};

cout<<firstindex(nums, 0, 7)<<" ";

return 0;
}