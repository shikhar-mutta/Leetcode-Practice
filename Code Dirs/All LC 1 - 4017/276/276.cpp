// Link: https://leetcode.com/problems/paint-fence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: DP tracking ways ending in "same color as previous post" vs "different color";
// same[i] = diff[i-1] (only one way to repeat: match the post before that), diff[i] = (same[i-1]+diff[i-1])*(k-1)
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        long long same = k, diff = (long long)k * (k - 1);
        for (int i = 3; i <= n; i++) {
            long long newDiff = (same + diff) * (k - 1);
            same = diff;
            diff = newDiff;
        }
        return (int)(same + diff);
    }
};
