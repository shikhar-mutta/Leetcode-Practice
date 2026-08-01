// Link: https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: For each subarray, we can compute the bitwise AND of its elements and check if it equals k. We can optimize this by keeping track of the current AND value as we extend the subarray. If the current AND value becomes less than k, we can break early since the AND operation can only decrease or stay the same as we add more elements. We can use a vector to store the current AND values for subarrays ending at each index and update it as we iterate through the array. This way, we can efficiently count the number of subarrays with an AND value equal to k.
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long total = 0;
        vector<pair<int, int>> prev;
        vector<pair<int, int>> curr;
        for (auto x : nums)
        {
            curr.clear();
            curr.push_back({x, 1});
            for (auto p : prev)
            {
                int val = p.first;
                int count = p.second;
                if ((val & x) == curr.back().first)
                    curr.back().second += count;
                else
                    curr.push_back({val & x, count});
            }
            for (auto x : curr)
            {
                if (x.first == k)
                    total += x.second;
            }
            prev.swap(curr);
        }
        return total;
    }
};