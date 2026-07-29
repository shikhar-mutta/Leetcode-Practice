// Link: https://leetcode.com/problems/palindrome-rearrangement-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+Q)*26), SC: O(N*26)
// Approach: map query range [c,d] into left-half coordinates via mirroring: R=[n-1-d, n-1-c].
// A query is valid iff (1) every left-half position outside L=[a,b] ∪ R already has
// s[i]==s[mirror(i)] (checked via a mismatch-count prefix sum with inclusion-exclusion over L,
// R, and their overlap), and (2) the character pools of s[a..b] and s[c..d] can be rearranged to
// satisfy every pairing: positions in L\R need their mirror's fixed char supplied from the left
// pool, positions in R\L need their own fixed char supplied from the right pool, and whatever's
// left over in both pools combined (covering the L∩R overlap, both sides free) must have every
// character appearing an even number of times.
class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int half = n / 2;

        vector<vector<int>> charPrefix(26, vector<int>(n+1, 0));
        for (int i = 0; i < n; i++) {
            for (int ch = 0; ch < 26; ch++) charPrefix[ch][i+1] = charPrefix[ch][i];
            charPrefix[s[i]-'a'][i+1]++;
        }

        vector<vector<int>> mirrorReqPrefix(26, vector<int>(half+1, 0));
        for (int j = 0; j < half; j++) {
            for (int ch = 0; ch < 26; ch++) mirrorReqPrefix[ch][j+1] = mirrorReqPrefix[ch][j];
            mirrorReqPrefix[s[n-1-j]-'a'][j+1]++;
        }

        vector<int> mismatchPrefix(half+1, 0);
        for (int j = 0; j < half; j++) mismatchPrefix[j+1] = mismatchPrefix[j] + (s[j] != s[n-1-j] ? 1 : 0);

        auto rangeCount = [](vector<int>& prefix, int l, int r) -> int {
            if (l > r) return 0;
            return prefix[r+1] - prefix[l];
        };
        auto rangeMismatch = [&](int l, int r) -> int {
            if (l > r) return 0;
            return mismatchPrefix[r+1] - mismatchPrefix[l];
        };

        vector<bool> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1], c = q[2], d = q[3];
            int cp = n-1-d, dp = n-1-c; // mirrored range R = [cp, dp]

            int overlapL = max(a, cp), overlapR = min(b, dp);
            bool overlapValid = overlapL <= overlapR;

            int totalMismatch = rangeMismatch(0, half-1);
            int outside = totalMismatch - rangeMismatch(a, b) - rangeMismatch(cp, dp)
                          + (overlapValid ? rangeMismatch(overlapL, overlapR) : 0);
            if (outside != 0) { ans.push_back(false); continue; }

            vector<int> cntLeft(26), cntRight(26);
            for (int ch = 0; ch < 26; ch++) {
                cntLeft[ch] = rangeCount(charPrefix[ch], a, b);
                cntRight[ch] = rangeCount(charPrefix[ch], c, d);
            }

            vector<pair<int,int>> onlyL, onlyR;
            if (overlapValid) {
                onlyL = {{a, overlapL-1}, {overlapR+1, b}};
                onlyR = {{cp, overlapL-1}, {overlapR+1, dp}};
            } else {
                onlyL = {{a, b}};
                onlyR = {{cp, dp}};
            }

            bool ok = true;
            for (auto& [l, r] : onlyL) {
                if (l > r) continue;
                for (int ch = 0; ch < 26; ch++) {
                    cntLeft[ch] -= rangeCount(mirrorReqPrefix[ch], l, r);
                    if (cntLeft[ch] < 0) ok = false;
                }
            }
            for (auto& [l, r] : onlyR) {
                if (l > r) continue;
                for (int ch = 0; ch < 26; ch++) {
                    cntRight[ch] -= rangeCount(charPrefix[ch], l, r);
                    if (cntRight[ch] < 0) ok = false;
                }
            }
            if (ok) {
                for (int ch = 0; ch < 26; ch++) {
                    if ((cntLeft[ch] + cntRight[ch]) % 2 != 0) { ok = false; break; }
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
