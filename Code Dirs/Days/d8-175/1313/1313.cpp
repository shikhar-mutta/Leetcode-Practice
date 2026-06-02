// Link: https://leetcode.com/problems/decompress-run-length-encoded-list/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        int freq, val, n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i += 2)
        {
            freq = nums[i];
            val = nums[i + 1];
            while (freq--)
                res.push_back(val);
        }
        return res;
    }
};
