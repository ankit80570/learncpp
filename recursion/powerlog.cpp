#include<bits/stdc++.h>
using namespace std;

int powerlog(int n, int x){
    if(x == 0){
        return 1;
    }
    int nx = powerlog(n, x/2)*powerlog(n, x/2);
    if(x % 2 != 0){
        nx = n*nx;
    }
    return nx;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

cout<<powerlog(4,3)<<" ";

return 0;
}