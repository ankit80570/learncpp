#include <bits/stdc++.h>
using namespace std;

void printdec(int n){
    if(n == 0){
        return;
    }
    cout<<n <<" ";
    printdec(n-1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    printdec(10);
    return 0;
}