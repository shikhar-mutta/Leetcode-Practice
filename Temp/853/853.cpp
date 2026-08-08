// Link: https://leetcode.com/problems/car-fleet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return position[a] > position[b]; });

        int fleets = 0;
        double curTime = -1;
        for (int i : idx) {
            double t = (double)(target - position[i]) / speed[i];
            if (t > curTime) {
                fleets++;
                curTime = t;
            }
        }
        return fleets;
    }
};
