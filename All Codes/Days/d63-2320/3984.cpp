// Link: https://leetcode.com/problems/divisible-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(max(nums))) SC: O(sqrt(max(nums)))
// Approach: For each prime factor p of any number in nums, compute the maximum score achievable by choosing p as the divisor. Keep track of the overall maximum score and the corresponding prime factor. Return the maximum score multiplied by the chosen prime factor, modulo 1e9 + 7.
class Solution
{
public:
    int divisibleGame(vector<int> &nums)
    {

        int n = nums.size();
        long long mod = 1e9 + 7;

        set<int> s;

        for (auto x : nums)
        {

            for (int j = 2; j * j <= x; j++)
            {
                if (x % j == 0)
                {
                    s.insert(j);
                    while (x % j == 0)
                        x = x / j;
                }

                if (x == 1)
                    break;
            }

            if (x > 1)
                s.insert(x);
        }

        s.insert(2);

        long long tot = INT_MIN;

        long long f = 2;

        for (auto it : s)
        {
            long long curr = 0;

            for (int i = 0; i < n; i++)
            {
                long long x = nums[i];

                if (x % it)
                {

                    if (i == 0)
                        curr = curr - x;
                    else
                        curr = max(-x, curr - x);
                }
                else
                    curr = max(x, curr + x);

                if (curr > tot)
                {
                    tot = curr;
                    f = it;
                }
            }
        }

        return (((tot % mod + mod) % mod) * f) % mod;
    }
};
