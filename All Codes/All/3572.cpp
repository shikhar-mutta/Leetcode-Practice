// Link: https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int> best;
        for (int i = 0; i < (int)x.size(); i++) {
            auto it = best.find(x[i]);
            if (it == best.end() || y[i] > it->second) best[x[i]] = y[i];
        }
        if (best.size() < 3) return -1;

        vector<int> vals;
        for (auto& [k, v] : best) vals.push_back(v);
        sort(vals.rbegin(), vals.rend());
        return vals[0] + vals[1] + vals[2];
    }
};
