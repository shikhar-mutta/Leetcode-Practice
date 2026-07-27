// Link: https://leetcode.com/problems/shift-distance-between-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26 * n) SC: O(1)
// Approach: for each position, shifting s[i] to t[i] can go all the way
// forward (accumulating nextCost per step) or all the way backward
// (accumulating previousCost per step) around the 26-letter ring; take
// the cheaper direction and sum over all positions.
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a', d = t[i] - 'a';
            long long fwd = 0;
            for (int cur = c; cur != d; cur = (cur + 1) % 26) fwd += nextCost[cur];
            long long bwd = 0;
            for (int cur = c; cur != d; cur = (cur - 1 + 26) % 26) bwd += previousCost[cur];
            total += min(fwd, bwd);
        }
        return total;
    }
};
