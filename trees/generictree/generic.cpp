#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node> children;
};

void display(node root){
    string str = root.data + "-> ";
    for(node child: root.children){
        str += child.data + ", ";
    }
    str += ".";
    cout<<str<<endl;
    for(node child: root.children){
        display(child);
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    node root;
    stack<node> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            node t;
            t.data = arr[i];
            if (st.size() > 0)
            {
                st.top().children.push_back(t);
                cout<<st.top().data<<endl;
                for(auto x: st.top().children){
                    cout<<x.data<<" ";
                }
                cout<<endl;
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    cout<<endl<<root.data<<endl;
    for(auto x: root.children){
        cout<<x.data<<" ";
    }
    display(root);
    return 0;
}