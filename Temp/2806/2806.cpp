// Link: https://leetcode.com/problems/account-balance-after-rounded-purchase/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rounded = ((purchaseAmount + 5) / 10) * 10;
        return 100 - rounded;
    }
};
