// Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n)
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int cnt = 0;
        for (int num : nums)
        {
            cnt += freq[num - k] + freq[num + k];
            freq[num]++;
        }
        return cnt;
    }

    // Time Complexity: O(n^2)
    int countKDifference(vector<int> &nums, int k)
    {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (abs(nums[i] - nums[j]) == k)
                    cnt++;
        return cnt;
    }
};
