// Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double computeTime(vector<int>& dist, int speed) {
        int n = dist.size();
        double total = 0;
        for (int i = 0; i < n - 1; i++) {
            total += ceil((double)dist[i] / speed);
        }
        total += (double)dist[n-1] / speed;
        return total;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;

        int lo = 1, hi = 10000000;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (computeTime(dist, mid) <= hour) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
