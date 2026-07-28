// Link: https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: maintain frequency count for each value, update maximum frequency
//  as we iterate through the array.
//  The frequency of a number is incremented when we encounter it, and if it is equal to k, we also increment the result and the count of numbers equal to k.
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int freq[51] = {0}, res = 0, cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            int num = nums[i];
            freq[num] = max(freq[num], cnt) + 1;
            if (num == k)
            {
                ++res;
                ++cnt;
            }
            res = max(res, freq[num]);
        }
        return res;
    }
};