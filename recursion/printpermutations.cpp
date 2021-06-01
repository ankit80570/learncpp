#include<bits/stdc++.h>
using namespace std;

void printpermutations( string s, string osf){
    if(s.size() == 0){
        cout<<osf<<endl;
        return;
    }
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        string s1(1,s[i]);
        string res = s.substr(0,i) + s.substr(i+1);
        // cout<<s1<<" "<<res<< " "<<osf+s1<<endl;
        printpermutations(res, osf+s1);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string s="abc";
printpermutations(s, "");

return 0;
}