// Link: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long sumRange(long long a, long long b) {
        // sum of integers from b to a inclusive, a >= b
        return (a + b) * (a - b + 1) / 2;
    }

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());
        int n = inventory.size();
        inventory.push_back(0);
        long long profit = 0;
        long long width = 0;
        for (int i = 0; i < n; i++) {
            width++;
            long long cur = inventory[i];
            long long next = inventory[i + 1];
            long long gap = cur - next;
            long long total = width * gap;
            if (total <= orders) {
                profit = (profit + width % MOD * (sumRange(cur, next + 1) % MOD)) % MOD;
                orders -= total;
            } else {
                long long full = orders / width;
                long long rem = orders % width;
                long long low = cur - full + 1;
                profit = (profit + width % MOD * (sumRange(cur, low) % MOD)) % MOD;
                profit = (profit + rem % MOD * ((low - 1) % MOD)) % MOD;
                orders = 0;
                break;
            }
        }
        return (int)(profit % MOD);
    }
};
