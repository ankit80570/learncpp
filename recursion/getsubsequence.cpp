#include<bits/stdc++.h>
using namespace std;

void getsubsequence(string s, int idx, vector<string>& result, string osf){
    if(idx == s.size()){
        result.push_back(osf);
        return;
    }
    getsubsequence(s, idx+1,result, osf);
    string s1(1,s[idx]);
    getsubsequence(s, idx+1, result, osf+s1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

string s = "abc";
vector<string> result={};
getsubsequence(s,0,result, "");
for(int i=0; i<result.size(); i++){
    cout<< result[i]<<endl;
}
return 0;
}