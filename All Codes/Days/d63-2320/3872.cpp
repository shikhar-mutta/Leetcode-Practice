// Link: https://leetcode.com/problems/longest-arithmetic-sequence-after-changing-at-most-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: f[i]/g[i] = length of the pure arithmetic run ending/starting
// at i. For each index i as the "changed" position: extending f[i-1] by
// one (set nums[i] to continue that run's difference), extending g[i+1]
// by one (set nums[i] to continue that run's difference from the right),
// or — if i is interior — bridging f[i-1] and g[i+1] together when the
// midpoint value nums[i-1] + (nums[i+1]-nums[i-1])/2 is an integer that
// matches both runs' differences.
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, 0);
        for (int i = 1; i < n; i++) d[i] = nums[i] - nums[i-1];

        vector<int> f(n, 2), g(n, 2);
        f[0] = 1; g[n-1] = 1;
        for (int i = 2; i < n; i++) if (d[i] == d[i-1]) f[i] = f[i-1] + 1;
        for (int i = n - 3; i >= 0; i--) if (d[i+1] == d[i+2]) g[i] = g[i+1] + 1;

        int ans = 3;
        for (int i = 0; i < n; i++) {
            ans = max({ans, f[i], g[i]});
            if (i > 0) ans = max(ans, f[i-1] + 1);
            if (i + 1 < n) ans = max(ans, g[i+1] + 1);
            if (i > 0 && i < n - 1) {
                int diffNum = nums[i+1] - nums[i-1];
                if (diffNum % 2 == 0) {
                    int diff = diffNum / 2;
                    int k = 3;
                    if (i > 1 && diff == d[i-1]) k += f[i-1] - 1;
                    if (i < n - 2 && diff == d[i+2]) k += g[i+1] - 1;
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};
