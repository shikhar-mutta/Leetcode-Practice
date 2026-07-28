// Link: https://leetcode.com/problems/jump-game-ix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: ans[n-1] = global max (can jump forward through any
// decreasing chain down to the max's position, then jump back up to it).
// Walking right to left, if preMax[i] (max of nums[0..i]) exceeds the
// smallest value seen so far to the right (sufMin), then from i we can
// jump forward to that smaller value, then back up to preMax[i]'s
// position, then forward again — reaching everything ans[i+1] reaches,
// so ans[i] = ans[i+1]. Otherwise ans[i] = preMax[i] (jump straight to
// the best value seen so far on the left).
class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> preMax(n), ans(n);
        preMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            preMax[i] = max(preMax[i - 1], nums[i]);

        ans[n - 1] = preMax[n - 1];
        long long sufMin = LLONG_MAX;
        for (int i = n - 2; i >= 0; i--)
        {
            if (preMax[i] > sufMin)
                ans[i] = ans[i + 1];
            else
                ans[i] = preMax[i];
            sufMin = min(sufMin, (long long)nums[i + 1]);
        }
        return ans;
    }
};
