// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, consecutive = 0;
        for (int b : bloomDay) {
            if (b <= day) {
                consecutive++;
                if (consecutive == k) { bouquets++; consecutive = 0; }
            } else {
                consecutive = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = (long long)m * k;
        if (need > (int)bloomDay.size()) return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(bloomDay, m, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
