// Link: https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n), SC: O(1)
// Approach: concat(a,b) appends b's binary representation after a's,
// simulating string concatenation via bit shifts. Sort the 3 numbers by a
// custom comparator that prefers whichever order (a before b, or b before
// a) yields the larger concatenated value, then concatenate them all in
// that order.
class Solution {
public:
    int concat(int a, int b) {
        int bits = 0, x = b;
        while (x) {
            bits++;
            x >>= 1;
        }
        return (a << bits) | b;
    }

    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return concat(a, b) > concat(b, a);
        });

        int ans = 0;
        for (int x : nums)
            ans = concat(ans, x);
        return ans;
    }
};
