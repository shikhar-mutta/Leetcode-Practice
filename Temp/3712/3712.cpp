// Link: https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int sumDivisibleByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        int sum = 0;
        for (auto &[num, count] : freq)
            if (count % k == 0)
                sum += num * count;
        return sum;
    }
};
