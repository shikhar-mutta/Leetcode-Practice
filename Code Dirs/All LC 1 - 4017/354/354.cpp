// Link: https://leetcode.com/problems/russian-doll-envelopes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort by width ascending, height descending on ties (so same-width
// envelopes can't nest); then LIS on heights via binary search
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        vector<int> tails;
        for (auto& e : envelopes) {
            int h = e[1];
            auto it = lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) tails.push_back(h);
            else *it = h;
        }
        return tails.size();
    }
};
