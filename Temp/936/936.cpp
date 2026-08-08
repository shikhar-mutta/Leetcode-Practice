// Link: https://leetcode.com/problems/stamping-the-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<bool> done(n, false);
        vector<int> result;
        int remaining = n;
        bool progress = true;

        while (remaining > 0 && progress) {
            progress = false;
            for (int i = 0; i + m <= n; i++) {
                bool canStamp = false;
                bool matches = true;
                for (int j = 0; j < m; j++) {
                    if (done[i + j]) continue;
                    if (target[i + j] != stamp[j]) { matches = false; break; }
                    canStamp = true;
                }
                if (matches && canStamp) {
                    for (int j = 0; j < m; j++) {
                        if (!done[i + j]) { done[i + j] = true; remaining--; }
                    }
                    result.push_back(i);
                    progress = true;
                }
            }
        }
        if (remaining > 0) return {};
        reverse(result.begin(), result.end());
        return result;
    }
};
