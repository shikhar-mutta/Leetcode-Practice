// Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k == n)
        {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        if (k == 1) // k == 1
        {
            int ans = -1;
            for (auto &[num, f] : freq)
            {
                if (f == 1)
                    ans = max(ans, num);
            }
            return ans;
        }

        //  Focus First & Last elements
        int a = nums[0];
        int b = nums[n - 1];

        bool first = (freq[a] == 1);
        bool last = (freq[b] == 1);

        if (first && last)
            return max(a, b);
        if (first)
            return a;
        if (last)
            return b;
        return -1;
    }
};