// Link: https://leetcode.com/problems/longest-ideal-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26), n = s.length()
// SC: O(1) (fixed 26-slot dp array)
// Approach: dp[c] = length of the longest ideal subsequence seen so far
// that ends with letter c. For each character in s, look at all letters
// within k of it (its valid predecessors) and extend the best one by 1;
// track the running best length seen.
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 0;

        for (char ch : s) {

            int curr = ch - 'a';
            int best = 0;
            for (int prev = max(0, curr - k); prev <= min(25, curr + k);
                 prev++) {

                best = max(best, dp[prev]);
            }

            dp[curr] = max(dp[curr], best + 1);

            ans = max(ans, dp[curr]);
        }

        return ans;
    }
};
