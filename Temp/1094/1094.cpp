// Link: https://leetcode.com/problems/car-pooling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> diff;
        for (auto& t : trips) {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }
        int cur = 0;
        for (auto& [pos, d] : diff) {
            cur += d;
            if (cur > capacity) return false;
        }
        return true;
    }
};
