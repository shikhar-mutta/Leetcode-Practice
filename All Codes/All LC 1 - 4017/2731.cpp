// Link: https://leetcode.com/problems/movement-of-robots/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(n)
    //  Approach:
    //  1. Calculate the final position of each robot after d seconds based on its initial position and direction.
    //  2. Sort the final positions of the robots.
    //  3. Use prefix sum to calculate the total distance between each pair of robots.
    //  4. Return the total distance modulo 10^9 + 7.
    int sumDistance(vector<int> &nums, string s, int d)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> pos(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            pos[i] = s[i] == 'L' ? 1LL * nums[i] - d : 1LL * nums[i] + d;
        }

        sort(pos.begin(), pos.end());

        long long prefix = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans = (ans + ((1LL * pos[i] * i - prefix))) % MOD;
            prefix += pos[i];
        }

        return (ans + MOD) % MOD;
    }
};