// Link: https://leetcode.com/problems/maximum-product-of-two-integers-with-no-common-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        const int BITS = 20;
        const int FULL = (1 << BITS) - 1;
        vector<int> maxForMask(1 << BITS, 0);

        for (int x : nums) maxForMask[x] = max(maxForMask[x], x);

        for (int bit = 0; bit < BITS; bit++) {
            for (int mask = 0; mask <= FULL; mask++) {
                if (mask & (1 << bit)) {
                    maxForMask[mask] = max(maxForMask[mask], maxForMask[mask ^ (1 << bit)]);
                }
            }
        }

        long long ans = 0;
        for (int x : nums) {
            int comp = FULL ^ x;
            int best = maxForMask[comp];
            if (best > 0) ans = max(ans, (long long)x * best);
        }

        return ans;
    }
};
