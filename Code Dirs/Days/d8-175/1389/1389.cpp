// Link: https://leetcode.com/problems/create-target-array-in-the-given-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans.insert(ans.begin() + index[i], nums[i]); // insert at the position index[i] the value nums[i] & TC is O(n) for insert() function, so overall TC is O(n^2)
        }
        return ans;
    }
};
