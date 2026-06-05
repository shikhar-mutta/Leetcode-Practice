// Link: https://leetcode.com/problems/minimum-number-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // sort + swap
    // TC: O(nlogn) + O(n) = O(nlogn). SC: O(n)
    vector<int> numberGame(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i += 2)
        {
            ans[i] = nums[i + 1];
            ans[i + 1] = nums[i];
        }
        return ans;
    }
};
