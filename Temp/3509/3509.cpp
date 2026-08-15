// Link: https://leetcode.com/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        if (k < -900 || k > 900) {
            return -1;
        }

        vector<bitset<1805>> dp0(limit + 1);
        vector<bitset<1805>> dp1(limit + 1);

        bitset<1805> reach0;
        bitset<1805> reach1;

        for (int x : nums) {
            if (x == 0) {
                dp0[0] |= reach1;
                dp1[0] |= reach0;
                dp1[0].set(900);

                bitset<1805> old_r0 = reach0;
                reach0 |= reach1;
                reach1 |= old_r0;
                reach1.set(900);
            } else {
                for (int p = limit / x; p >= 0; --p) {
                    bitset<1805> new_0 = dp1[p] >> x;
                    bitset<1805> new_1 = dp0[p] << x;
                    dp0[p * x] |= new_0;
                    dp1[p * x] |= new_1;
                }

                if (x <= limit) {
                    dp1[x].set(900 + x);
                }

                bitset<1805> new_r0 = reach1 >> x;
                bitset<1805> new_r1 = reach0 << x;
                reach0 |= new_r0;
                reach1 |= new_r1;
                reach1.set(900 + x);
            }
        }

        int target = 900 + k;
        for (int p = limit; p >= 0; --p) {
            if (dp0[p].test(target) || dp1[p].test(target)) {
                return p;
            }
        }

        return -1;
    }
};
