// Link: https://leetcode.com/problems/number-of-ways-to-split-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        if (ones % 3 != 0) return 0;
        if (ones == 0) {
            long long ways = (long long)(n - 1) * (n - 2) / 2 % MOD;
            return (int)ways;
        }

        int each = ones / 3;
        vector<int> onePositions;
        for (int i = 0; i < n; i++) if (s[i] == '1') onePositions.push_back(i);

        int firstCut = onePositions[each - 1];
        int firstCutEnd = onePositions[each];
        int secondCut = onePositions[2*each - 1];
        int secondCutEnd = onePositions[2*each];

        long long waysFirst = firstCutEnd - firstCut;
        long long waysSecond = secondCutEnd - secondCut;
        return (int)((waysFirst * waysSecond) % MOD);
    }
};
