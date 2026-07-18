// Link: https://leetcode.com/problems/counting-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach: DP
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);
        // EX:  i = 13--> 1101, i >> 1 = 110, i & 1 = 1, result[13] = result[6] + 1
        for (int i = 1; i <= n; i++) // DP relation: result[i] = result[i >> 1] + (i & 1)
            result[i] = result[i >> 1] + (i & 1);
        return result;
    }
};
