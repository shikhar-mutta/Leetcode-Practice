// Link: https://leetcode.com/problems/number-of-different-subsequences-gcds/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> present(maxVal + 1, false);
        for (int x : nums) present[x] = true;

        int count = 0;
        for (int g = 1; g <= maxVal; g++) {
            int curGcd = 0;
            for (int m = g; m <= maxVal; m += g) {
                if (present[m]) {
                    curGcd = gcd(curGcd, m);
                    if (curGcd == g) break;
                }
            }
            if (curGcd == g) count++;
        }
        return count;
    }
};
