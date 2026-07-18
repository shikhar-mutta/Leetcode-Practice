// Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    int maxOperations(vector<int> &nums)
    {
        int cnt = 0, n = nums.size(), sun = nums[0] + nums[1];
        for (int i = 0; i < n; i += 2)
        {
            if (nums[i] + nums[i + 1] == sun)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};
