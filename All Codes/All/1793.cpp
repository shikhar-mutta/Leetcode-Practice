// Link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: two pointers starting at k, greedily expand toward whichever
// neighbor has the larger value (since the min in range determines score),
// tracking min so far and updating best = min * width at each expansion.
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = k, r = k;
        int minVal = nums[k];
        int ans = minVal;
        while (l > 0 || r < n - 1)
        {
            int leftVal = (l > 0) ? nums[l - 1] : -1;
            int rightVal = (r < n - 1) ? nums[r + 1] : -1;
            if (leftVal >= rightVal)
                l--;
            else
                r++;
            minVal = min({minVal, nums[l], nums[r]});
            ans = max(ans, minVal * (r - l + 1));
        }
        return ans;
    }
};
