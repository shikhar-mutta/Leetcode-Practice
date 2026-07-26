// Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + total garbage length), n = garbage.size()
// SC: O(n) for the travel prefix sums
// Approach: convert travel into a prefix sum so travel[i-1] = total time to
// reach house i from house 0. Every unit of garbage costs 1 second
// regardless of truck, so sum all garbage string lengths unconditionally.
// For the travel cost: scan houses from the last down to 1, and for each
// truck type (M/P/G), the FIRST time (in this backward scan) its letter is
// seen marks the LAST house that truck must visit, so add that house's
// prefix travel time once per truck type and stop looking for it again.
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        bool mStart = false;
        bool pStart = false;
        bool gStart = false;
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i] + travel[i - 1];
        }
        int n = garbage.size();
        int total = 0;
        for (int i = n - 1; i > 0; i--) {
            if (mStart && pStart && gStart) {
                total += garbage[i].size();
            } else {
                for (char c : garbage[i]) {
                    if (c == 'M' && !mStart) {
                        mStart = true;
                        total += travel[i - 1];
                    } else if (c == 'P' && !pStart) {
                        pStart = true;
                        total += travel[i - 1];
                    } else if (c == 'G' && !gStart) {
                        gStart = true;
                        total += travel[i - 1];
                    }
                }
                total += garbage[i].size();
            }
        }
        return total + garbage[0].size();
    }
};
