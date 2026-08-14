// Link: https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long reach = 0;
        int idx = 0, n = coins.size(), ans = 0;
        while (reach < target) {
            if (idx < n && coins[idx] <= reach + 1) {
                reach += coins[idx];
                idx++;
            } else {
                reach += reach + 1;
                ans++;
            }
        }
        return ans;
    }
};
