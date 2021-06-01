#include<bits/stdc++.h>
using namespace std;

void printinc(int n){
    if(n == 0){
        return;
    }
    printinc(n-1);
    cout<<n<<" ";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

printinc(10);

return 0;
}