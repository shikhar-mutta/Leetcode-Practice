// Link: https://leetcode.com/problems/4-keys-keyboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: dp[i] = max A's producible with i keystrokes. Base dp[i]=i (plain A presses). For i>=7, try every breakpoint j: use j keystrokes to reach dp[j] A's, then Ctrl+A, Ctrl+C (2 keys), then paste the remaining (i-j-2) times, giving dp[j]*(1+i-j-2) = dp[j]*(i-j-1).
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1);
        for (int i = 0; i <= n; i++) dp[i] = i;
        for (int i = 7; i <= n; i++) {
            for (int j = 1; j <= i-3; j++) {
                dp[i] = max(dp[i], dp[j] * (i-j-1));
            }
        }
        return dp[n];
    }
};
