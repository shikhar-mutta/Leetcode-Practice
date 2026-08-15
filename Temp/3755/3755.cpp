// Link: https://leetcode.com/problems/find-maximum-balanced-xor-subarray-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Use a map of prefix XOR and balance to store the first index of each unique pair.
    int maxBalancedSubarray(vector<int> &nums)
    {
        int len = nums.size(), prefix = 0, balance = 0, ans = 0;
        struct PairHash
        {
            size_t operator()(const pair<int, int> &p) const
            {
                return hash<long long>()((long long)p.first << 32 ^ (unsigned)p.second);
            }
        };
        unordered_map<pair<int, int>, int, PairHash> first;

        first[{0, 0}] = 0; // Initialize the first index for prefix=0 and balance=0
        for (int i = 0; i < len; i++)
        {
            prefix ^= nums[i];
            balance += (nums[i] % 2 == 0) ? 1 : -1;
            pair<int, int> key = {prefix, balance}; // Create a key for the current prefix and balance
            auto it = first.find(key);              // Check if this key has been seen before
            if (it != first.end())
                ans = max(ans, (i + 1) - it->second); // Update the maximum length of the balanced subarray
            else
                first[key] = i + 1;
        }
        return ans;
    }
};