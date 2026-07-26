// Link: https://leetcode.com/problems/account-balance-after-rounded-purchase/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: round purchaseAmount to the nearest multiple of 10 (ties round
// up, via the +5 before integer-dividing by 10), then subtract from 100.
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rounded =
            (purchaseAmount + 5) / 10 * 10; // round to nearest 10, ties up
        return 100 - rounded;
    }
};
