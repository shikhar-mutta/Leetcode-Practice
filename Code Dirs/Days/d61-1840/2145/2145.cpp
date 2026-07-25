// Link: https://leetcode.com/problems/count-the-hidden-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the hidden array's shape (relative to an arbitrary starting
// value) is fixed by the running prefix sum of differences; only the
// starting value can vary. Track the min/max of that running prefix (with
// x starting at an arbitrary anchor, here 'lower') to get the required
// span; shifting so the minimum lands exactly on lower fixes the one degree
// of freedom, and the number of valid starting values equals how much room
// is left between the shifted maximum and upper (0 if it overshoots).
class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        int n = dif.size();
        long long x = lower;
        long long maxi = x;
        long long mini = x;
        for (int i = 0; i < n; i++) {
            x += dif[i];
            maxi = max(x, maxi);
            mini = min(x, mini);
        }
        if (mini < lower) {
            int d = lower - mini;
            mini += d;
            maxi += d;
        }
        if (maxi > upper) {
            return 0;
        }
        return upper - maxi + 1;
    }
};
