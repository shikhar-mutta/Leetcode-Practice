// Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool feasible(vector<int>& quantities, int n, int cap) {
        int stores = 0;
        for (int q : quantities) stores += (q + cap - 1) / cap;
        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(quantities, n, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
