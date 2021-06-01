#include<bits/stdc++.h>
using namespace std;

void printsubsets(string s, string osf, int idx){
    if(idx == s.size()){
        cout<<osf<<endl;
        return;
    }
    printsubsets(s, osf, idx+1);
    printsubsets(s, osf+s[idx], idx+1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string s = "abc";
printsubsets(s, "", 0);

return 0;
}