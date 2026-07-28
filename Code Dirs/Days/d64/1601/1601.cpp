// Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int r = requests.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << r); mask++) {
            vector<int> deg(n, 0);
            int cnt = __builtin_popcount(mask);
            if (cnt <= ans) continue;
            for (int i = 0; i < r; i++) {
                if (mask & (1 << i)) {
                    deg[requests[i][0]]--;
                    deg[requests[i][1]]++;
                }
            }
            bool ok = true;
            for (int d : deg) if (d != 0) { ok = false; break; }
            if (ok) ans = cnt;
        }
        return ans;
    }
};
