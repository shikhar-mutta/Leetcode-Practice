// Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: collect indices of seats. If count odd or zero, return 0. For
// each pair of seats (2i-1, 2i) (1-indexed within pairs), multiply the
// number of empty positions between seat[2i-1] and seat[2i]+1 (exclusive)
// into the answer, mod 1e9+7.
class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> pos;
        for (int i = 0; i < (int)corridor.size(); i++)
            if (corridor[i] == 'S') pos.push_back(i);
        int m = pos.size();
        if (m == 0 || m % 2 != 0) return 0;
        long long ans = 1;
        for (int i = 2; i < m; i += 2) {
            long long gap = pos[i] - pos[i - 1];
            ans = (ans * gap) % MOD;
        }
        return (int)ans;
    }
};
