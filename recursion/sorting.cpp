#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &nums, int val)
{
    if (nums.size() == 0 || nums.back() <= val)
    {
        nums.push_back(val);
        return;
    }
    int value = nums.back();
    nums.pop_back();
    insert(nums, val);
    nums.push_back(value);
}
void sort(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return;
    }
    int val = nums.back();
    nums.pop_back();
    sort(nums);
    insert(nums, val);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums = {7, 1, 4, 5, 9, 3, 2};
    sort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}