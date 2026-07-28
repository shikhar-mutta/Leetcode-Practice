// Link: https://leetcode.com/problems/number-of-different-subsequences-gcds/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(maxVal * log(maxVal))  SC: O(maxVal)
// Approach: for each candidate g from 1..maxVal, walk its multiples present in
// nums and accumulate their gcd; if that running gcd reaches g, some subsequence
// of multiples of g has gcd exactly g, so count it.
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> present(mx + 1, false);
        for (int x : nums) present[x] = true;
        int ans = 0;
        for (int g = 1; g <= mx; g++) {
            int cur = 0;
            for (int m = g; m <= mx; m += g) {
                if (present[m]) {
                    cur = cur == 0 ? m : __gcd(cur, m);
                    if (cur == g) break;
                }
            }
            if (cur == g) ans++;
        }
        return ans;
    }
};
