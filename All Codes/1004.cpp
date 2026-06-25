// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, zeros = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++)
        {
            if (nums[right] == 0)
                zeros++;
            while (zeros > k)
            { // too many zeros: shrink from left
                if (nums[left] == 0)
                    zeros--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
