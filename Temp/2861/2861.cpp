// Link: https://leetcode.com/problems/maximum-number-of-alloys/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool feasible(int n, vector<int>& comp, vector<int>& stock, vector<int>& cost, long long x, long long budget) {
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long need = (long long)comp[i] * x - stock[i];
            if (need > 0) total += need * cost[i];
            if (total > budget) return false;
        }
        return total <= budget;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans = 0;
        for (int m = 0; m < k; m++) {
            long long lo = 0, hi = 2e9;
            while (lo < hi) {
                long long mid = lo + (hi - lo + 1) / 2;
                if (feasible(n, composition[m], stock, cost, mid, budget)) lo = mid;
                else hi = mid - 1;
            }
            ans = max(ans, lo);
        }
        return (int)ans;
    }
};
