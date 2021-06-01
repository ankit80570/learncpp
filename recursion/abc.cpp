#include<bits/stdc++.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string s = "abcdef";
string res = s.substr(0,3) + s.substr(4);
cout<<res;
return 0;
}