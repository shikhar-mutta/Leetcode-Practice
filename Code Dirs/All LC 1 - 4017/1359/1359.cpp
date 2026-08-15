// Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        const long long MOD = 1e9 + 7;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            long long slots = 2 * i - 1;
            res = res * slots % MOD * i % MOD;
        }
        return (int)res;
    }
};
