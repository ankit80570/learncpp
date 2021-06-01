#include<bits/stdc++.h>
using namespace std;

int findmax(vector<int> nums, int idx){
    if(idx == nums.size()-1)
        return nums[idx];
    int maxnum = findmax(nums, idx+1);
    return max(maxnum, nums[idx]);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int> nums = { 2, 5 ,3 ,1 ,7};
cout<<findmax(nums,0)<<" ";

return 0;
}