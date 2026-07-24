// Link: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(1)
    //  Approach: Brute Force
    //    1. We can iterate through the nums array and check if any of the groups can be found starting from the current position.
    //    2. If we find a group, we can move the position forward by the size of the group and continue checking for the next group.
    //    3. If we reach the end of the nums array and have found all the groups, we can return true. Otherwise, we return false.
    //  Note: This is a brute force solution and can be optimized using KMP algorithm or Rabin-Karp algorithm.
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int pos = 0;
        for (auto &g : groups)
        {
            int m = g.size(), n = nums.size();
            bool found = false;
            for (int i = pos; i + m <= n; ++i)
            {
                if (equal(g.begin(), g.end(), nums.begin() + i))
                {
                    pos = i + m;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};