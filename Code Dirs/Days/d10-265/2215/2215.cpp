// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using Hash sets. TC: O(n + m), SC: O(n + m)
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);
        for (auto it : st1)
            if (!st2.count(it))
                ans[0].push_back(it);

        for (auto it : st2)
            if (!st1.count(it))
                ans[1].push_back(it);
        return ans;
    }
};
