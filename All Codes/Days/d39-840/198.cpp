// Link: https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: DP, take = best ending with robbing current, skip = best without
    int rob(vector<int> &nums)
    {
        // take = best ending with robbing current, skip = best without
        int take = 0, skip = 0;
        for (int x : nums)
        {
            int newTake = skip + x;
            skip = max(skip, take);
            take = newTake;
        }
        return max(take, skip);
    }
};
