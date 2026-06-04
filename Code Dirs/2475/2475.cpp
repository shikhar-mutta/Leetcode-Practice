// Link: https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: brute force. TC: O(n^3), SC: O(1)
    int unequalTriplets(vector<int> &nums)
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                        cnt++;
        return cnt;
    }
};
