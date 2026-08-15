// Link: https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> prefixCost(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixCost[i] = min(prefixCost[i - 1] + (s[i - 1] == '1' ? 2 : 0), i);
        }
        vector<int> suffixCost(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int rem = n - i;
            suffixCost[i] = min(suffixCost[i + 1] + (s[i] == '1' ? 2 : 0), rem);
        }
        int best = INT_MAX;
        for (int i = 0; i <= n; i++) best = min(best, prefixCost[i] + suffixCost[i]);
        return best;
    }
};
