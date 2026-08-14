// Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> pos;
        for (int i = 0; i < (int)corridor.size(); i++) if (corridor[i] == 'S') pos.push_back(i);
        int k = pos.size();
        if (k == 0 || k % 2 != 0) return 0;
        long long result = 1;
        for (int i = 2; i < k; i += 2) {
            long long gap = pos[i] - pos[i - 1];
            result = (result * gap) % MOD;
        }
        return (int)result;
    }
};
