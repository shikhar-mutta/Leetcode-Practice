// Link: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();

        auto countPicks = [&](int minDiff) {
            int count = 1;
            int last = price[0];
            for (int i = 1; i < n; i++) {
                if (price[i] - last >= minDiff) {
                    count++;
                    last = price[i];
                }
            }
            return count;
        };

        int lo = 0, hi = price[n-1] - price[0];
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (countPicks(mid) >= k) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
