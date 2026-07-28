// Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: building the sequence order by order, inserting the i-th
// pickup/delivery pair into a sequence that already has 2(i-1) slots
// filled: there are (2i-1) choices for the pickup's position among the
// 2i-1 gaps, then (2i-1) or... precisely the pickup can go in any of
// the 2i-1 positions and the delivery in any position after it among
// the remaining, giving a factor of i*(2i-1) per step (standard
// combinatorial result). Multiply these factors for i=1..n, mod 1e9+7.
class Solution {
public:
    int countOrders(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * i % MOD;
            ans = ans * (2 * i - 1) % MOD;
        }
        return (int)ans;
    }
};
