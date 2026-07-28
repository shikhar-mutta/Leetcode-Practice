// Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: dp[i] = best total energy starting a chain at room i (adding
// energy[i] plus whatever dp[i+k] already accumulated). Computed right to
// left so dp[i+k] is ready; the answer is the max dp[i] over all start rooms.
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);

        return ans;
    }
};
