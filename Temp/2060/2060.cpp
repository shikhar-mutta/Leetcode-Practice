// Link: https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string S1, S2;
    int n1, n2;
    unordered_map<long long, int> memo;

    long long key(int i, int j, int diff) {
        return ((long long)i * 41 + j) * 8001 + (diff + 4000);
    }

    bool dp(int i, int j, int diff) {
        long long k = key(i, j, diff);
        auto it = memo.find(k);
        if (it != memo.end()) return it->second;

        bool res = false;
        if (i == n1 && j == n2) {
            res = (diff == 0);
        } else {
            if (!res && i < n1 && isdigit(S1[i])) {
                long long val = 0;
                for (int len = 1; i + len <= n1 && isdigit(S1[i + len - 1]); len++) {
                    if (len > 1 && S1[i] == '0') break;
                    val = val * 10 + (S1[i + len - 1] - '0');
                    if (val > 4000) break;
                    if (dp(i + len, j, (int)(diff - val))) { res = true; break; }
                }
            }
            if (!res && j < n2 && isdigit(S2[j])) {
                long long val = 0;
                for (int len = 1; j + len <= n2 && isdigit(S2[j + len - 1]); len++) {
                    if (len > 1 && S2[j] == '0') break;
                    val = val * 10 + (S2[j + len - 1] - '0');
                    if (val > 4000) break;
                    if (dp(i, j + len, (int)(diff + val))) { res = true; break; }
                }
            }
            if (!res) {
                if (diff == 0) {
                    if (i < n1 && j < n2 && !isdigit(S1[i]) && !isdigit(S2[j]) && S1[i] == S2[j]) {
                        res = dp(i + 1, j + 1, 0);
                    }
                } else if (diff > 0) {
                    if (i < n1 && !isdigit(S1[i])) res = dp(i + 1, j, diff - 1);
                } else {
                    if (j < n2 && !isdigit(S2[j])) res = dp(i, j + 1, diff + 1);
                }
            }
        }
        memo[k] = res;
        return res;
    }

    bool possiblyEquals(string s1, string s2) {
        S1 = s1; S2 = s2;
        n1 = s1.size(); n2 = s2.size();
        memo.clear();
        return dp(0, 0, 0);
    }
};
