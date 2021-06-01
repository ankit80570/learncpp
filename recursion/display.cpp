#include<bits/stdc++.h>
using namespace std;

void display (vector<int> nums, int idx){
    if(idx == 0){
        cout<<nums[idx]<<" ";
        return;
    }
    display(nums, idx-1);
    cout<<nums[idx]<<" ";
}

void displayrev(vector<int> nums, int idx){
    if(idx == nums.size()){
        return;
    }
    displayrev(nums, idx+1);
    cout<<nums[idx]<<" ";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int> nums = {1,2,3,4,5,6};
displayrev(nums, 0);

return 0;
}