// Link: https://leetcode.com/problems/corporate-flight-bookings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        for (auto& b : bookings) {
            diff[b[0]] += b[2];
            diff[b[1]+1] -= b[2];
        }
        vector<int> res(n);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += diff[i];
            res[i-1] = cur;
        }
        return res;
    }
};
