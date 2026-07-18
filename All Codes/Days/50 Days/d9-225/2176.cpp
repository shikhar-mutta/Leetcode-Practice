// Link: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Brute Force. TC: O(n^2) SC: O(1)
    int countPairs(vector<int> &nums, int k)
    {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    cnt++;
        return cnt;
    }
};
