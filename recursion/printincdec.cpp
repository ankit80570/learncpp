#include<bits/stdc++.h>
using namespace std;

void printincdec(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    printincdec(n-1);
    cout<<n<<" ";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

printincdec(10);

return 0;
}