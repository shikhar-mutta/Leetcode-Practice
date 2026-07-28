// Link: https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum of |strs[i]|)  SC: O(n)
// Approach: sorting a subsequence (0s before 1s) can only push 1's
// rightward, so t is reachable from s iff total ones match and every
// prefix of t has ones-count <= the corresponding prefix ones-count of
// s. For a candidate strs[i], the assignment that best satisfies this
// (lowest possible prefix counts for a fixed total) sets the needed
// number of '?' to '1' choosing the rightmost '?' positions.
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> prefS(n + 1, 0);
        for (int i = 0; i < n; i++) prefS[i + 1] = prefS[i] + (s[i] == '1');
        int onesS = prefS[n];

        vector<bool> ans;
        for (string& t : strs) {
            int fixed1 = 0, numQ = 0;
            for (char c : t) {
                if (c == '1') fixed1++;
                else if (c == '?') numQ++;
            }
            int need = onesS - fixed1;
            if (need < 0 || need > numQ) { ans.push_back(false); continue; }

            // mark the rightmost `need` '?' positions as '1'
            vector<char> resolved(t.begin(), t.end());
            int toSet = need;
            for (int i = n - 1; i >= 0 && toSet > 0; i--) {
                if (resolved[i] == '?') { resolved[i] = '1'; toSet--; }
            }
            for (int i = 0; i < n; i++) if (resolved[i] == '?') resolved[i] = '0';

            bool ok = true;
            int prefT = 0;
            for (int i = 0; i < n; i++) {
                prefT += (resolved[i] == '1');
                if (prefT > prefS[i + 1]) { ok = false; break; }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
