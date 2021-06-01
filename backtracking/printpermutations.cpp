#include<bits/stdc++.h>
using namespace std;

void printpermutations(string s, int idx){
    if(s.size() == idx){
        cout<<s<<endl;
        return;
    }
    for(int i=idx; i<s.size(); i++){
        swap(s[i],s[idx]);
        printpermutations(s,idx+1);
        swap(s[i],s[idx]);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string s = "abc";
printpermutations(s,0);

return 0;
}