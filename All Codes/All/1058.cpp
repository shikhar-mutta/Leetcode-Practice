// Link: https://leetcode.com/problems/minimize-rounding-error-to-meet-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        vector<double> vals(n);
        long long floorSum = 0;
        for (int i = 0; i < n; i++) {
            vals[i] = stod(prices[i]);
            floorSum += (long long)floor(vals[i]);
        }
        long long ceilSum = floorSum + n;
        if (target < floorSum || target > ceilSum) return "-1";

        int roundUps = target - floorSum;
        vector<double> fracs;
        for (int i = 0; i < n; i++) fracs.push_back(vals[i] - floor(vals[i]));
        sort(fracs.rbegin(), fracs.rend());

        double error = 0;
        for (int i = 0; i < n; i++) {
            if (i < roundUps) error += 1 - fracs[i];
            else error += fracs[i];
        }
        char buf[32];
        snprintf(buf, sizeof(buf), "%.3f", error);
        return string(buf);
    }
};
