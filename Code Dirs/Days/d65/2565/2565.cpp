// Link: https://leetcode.com/problems/subsequence-with-the-minimum-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: pre[i] = max chars of t greedily matched as a subsequence using s[0:i]; suf[i] = max
// trailing chars of t matched using s[i:n]. Removing s[l:r) leaves a valid subsequence iff
// pre[l] + suf[r] >= m; minimize (m - pre[i] - suf[i]) over all split points i.
class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> pre(n+1, 0), suf(n+1, 0);
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i];
            if (pre[i+1] < m && s[i] == t[pre[i+1]]) pre[i+1]++;
        }
        int j = m;
        suf[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            suf[i] = suf[i+1];
            if (j > 0 && s[i] == t[j-1]) { j--; suf[i] = m - j; }
        }

        int ans = m;
        for (int i = 0; i <= n; i++) ans = min(ans, max(0, m - pre[i] - suf[i]));
        return ans;
    }
};
