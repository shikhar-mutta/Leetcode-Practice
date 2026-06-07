// Link: https://leetcode.com/problems/make-array-elements-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    int countValidSelections(vector<int> &nums)
    {
        int total = 0;
        for (int x : nums)
            total += x; // count the total sum of the array

        int left = 0, ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                left += nums[i];
            else
            {
                int right = total - left; // Cal right
                if (left == right)        // equal
                    ans += 2;
                else if (abs(left - right) == 1) // abs diff
                    ans += 1;
            }
        }
        return ans;
    }
};
