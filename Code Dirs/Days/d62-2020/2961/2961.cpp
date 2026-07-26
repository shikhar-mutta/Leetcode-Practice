// Link: https://leetcode.com/problems/double-modular-exponentiation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(b, c))) – for each of n variables, two modPow calls:
//     O(log b) for a^b mod 10, O(log c) for x^c mod m
// SC: O(1) extra – only the output vector (not counted as auxiliary space)
// Approach: For each variable [a, b, c, m], compute in two steps:
//   Step 1: x = (a^b) mod 10   (last digit of a^b)
//   Step 2: y = x^c mod m
//   If y == target, record index i.
// Uses fast modular exponentiation (binary exponentiation) for both steps.
class Solution
{
public:
    long long modPow(long long a, long long b, long long mod)
    {
        long long res = 1 % mod;
        a %= mod;
        while (b)
        {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> ans;

        for (int i = 0; i < variables.size(); i++)
        {
            long long a = variables[i][0];
            long long b = variables[i][1];
            long long c = variables[i][2];
            long long m = variables[i][3];

            long long x = modPow(a, b, 10);
            long long y = modPow(x, c, m);

            if (y == target)
                ans.push_back(i);
        }

        return ans;
    }
};