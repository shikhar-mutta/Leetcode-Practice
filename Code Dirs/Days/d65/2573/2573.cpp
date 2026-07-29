// Link: https://leetcode.com/problems/find-the-string-with-lcp/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N^2)
// Approach: greedily build the lexicographically smallest candidate — scan i left to right;
// if s[i] unset, assign the next unused letter, and propagate that letter to every j>i with
// lcp[i][j]>0 (they must share the same character). Then recompute the actual LCP table from
// the built string and verify it matches the input exactly; mismatch or running out of letters
// means no valid string exists.
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 0);
        char next = 'a';
        for (int i = 0; i < n; i++) {
            if (s[i] != 0) continue;
            if (next > 'z') return "";
            s[i] = next++;
            for (int j = i+1; j < n; j++) {
                if (lcp[i][j] > 0) s[j] = s[i];
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                dp[i][j] = (s[i] == s[j]) ? dp[i+1][j+1] + 1 : 0;
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }
        return s;
    }
};
