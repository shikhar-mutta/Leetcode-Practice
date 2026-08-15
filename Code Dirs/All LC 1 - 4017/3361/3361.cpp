// Link: https://leetcode.com/problems/shift-distance-between-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        // doubled prefix sums for next (forward)
        vector<long long> prefNext(53, 0);
        for (int i = 0; i < 52; i++) prefNext[i+1] = prefNext[i] + nextCost[i % 26];

        // doubled prefix sums for previous (backward), indexed so that
        // prefPrev[i] = sum of previousCost values going backward starting appropriately
        vector<long long> prefPrev(53, 0);
        for (int i = 0; i < 52; i++) prefPrev[i+1] = prefPrev[i] + previousCost[25 - (i % 26)];

        long long total = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a', b = t[i] - 'a';
            int stepsFwd = (b - a + 26) % 26;
            long long costFwd = prefNext[a + stepsFwd] - prefNext[a];

            int stepsBack = (a - b + 26) % 26;
            // going backward from a: costs previousCost[a], previousCost[a-1], ..., previousCost[a-stepsBack+1]
            // using reversed doubled array: index mapping so start = 25-a
            int start = 25 - a;
            long long costBack = prefPrev[start + stepsBack] - prefPrev[start];

            total += min(costFwd, costBack);
        }
        return total;
    }
};
