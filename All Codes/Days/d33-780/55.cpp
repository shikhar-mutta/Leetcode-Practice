// Link: https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    bool canJump(vector<int> &nums)
    {
        int reach = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (i > reach)
                return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};
