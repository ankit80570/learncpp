#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> partition(string s) {
//     vector<vector<string>> result;
//     helper(s,result,0,"");
//     return result;
// }
void helper(string s, vector<vector<string>> result, int idx, string osf)
{
    if (idx == s.size())
        return;

    if (!osf.empty())
    {   
        if(helper2(osf, 0, osf.size()))
            cout << osf << endl;
    }

    for (int i = idx; i < s.size(); i++)
    {
        osf += s[i];
        helper(s, result, idx + 1, osf);
        osf = osf.erase(osf.size() - 1);
    }
}
bool helper2(string s, int low, int high)
{
    while (low < high)
    {
        if (s[low++] != s[high--])
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s = "aab";
    vector<vector<string>> result;
    helper(s, result, 0, "");
    // result = partition(s);
    // for(auto &s1: result){
    //     cout<< &s1;
    // }
    return 0;
}