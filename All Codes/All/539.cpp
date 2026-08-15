// Link: https://leetcode.com/problems/minimum-time-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: convert to minutes, sort, take min adjacent gap including the
// circular wrap-around gap
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto& t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            mins.push_back(h * 60 + m);
        }
        sort(mins.begin(), mins.end());

        int best = INT_MAX;
        int n = mins.size();
        for (int i = 1; i < n; i++) best = min(best, mins[i] - mins[i-1]);
        best = min(best, 1440 - mins[n-1] + mins[0]);
        return best;
    }
};
