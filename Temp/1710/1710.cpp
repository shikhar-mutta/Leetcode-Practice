// Link: https://leetcode.com/problems/maximum-units-on-a-truck/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int total = 0;
        for (auto& b : boxTypes) {
            int take = min(b[0], truckSize);
            total += take * b[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }
        return total;
    }
};
