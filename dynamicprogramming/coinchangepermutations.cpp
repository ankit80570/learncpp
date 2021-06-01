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
vector<int> perm(k+1,0);
perm[0] =1;

for(int i=0; i<=k; i++){
    for(auto num: nums){
        if(num <= i){
            perm[i] = perm[i] + perm[i-num];
        }
    }
}

cout<<perm[k]<<endl;
return 0;
}