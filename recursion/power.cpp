#include<bits/stdc++.h>
using namespace std;

int power(int n, int x){
    if(x == 0){
        return 1;
    }
    return n*power(n,x-1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

cout<<power(3,2)<<" ";

return 0;
}