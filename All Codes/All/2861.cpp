// Link: https://leetcode.com/problems/maximum-number-of-alloys/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(maxAlloys) * k * n)
// SC: O(1)
// Approach: binary search on the answer (number of alloys producible).
// check(mid) tries every machine independently: cost to reach `mid` alloys on
// a machine is sum over metals of max(0, composition[metal]*mid - stock) *
// cost[metal]; feasible overall if ANY machine's cost <= budget. Binary
// search the largest feasible count.
class Solution {
public:
    bool check(vector<vector<int>>& composition, vector<int>& stock,
               vector<int>& cost, int k, int budget, long long mid) {

        // Try each machine
        for (int machine = 0; machine < k; machine++) {

            long long money = 0;

            // Calculate cost for this machine
            for (int metal = 0; metal < stock.size(); metal++) {

                long long required = 1LL * composition[machine][metal] * mid;

                if (required > stock[metal]) {
                    money += (required - stock[metal]) * cost[metal];
                }

                if (money > budget)
                    break;
            }

            if (money <= budget)
                return true;
        }

        return false;
    }

    int maxNumberOfAlloys(int n, int k, int budget,
                          vector<vector<int>>& composition, vector<int>& stock,
                          vector<int>& cost) {

        long long low = 0;
        long long high = 1e9;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(composition, stock, cost, k, budget, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};