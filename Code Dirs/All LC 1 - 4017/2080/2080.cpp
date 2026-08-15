// Link: https://leetcode.com/problems/range-frequency-queries/description/

#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
    unordered_map<int, vector<int>> positions;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); i++) positions[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        auto it = positions.find(value);
        if (it == positions.end()) return 0;
        auto& v = it->second;
        int lo = lower_bound(v.begin(), v.end(), left) - v.begin();
        int hi = upper_bound(v.begin(), v.end(), right) - v.begin();
        return hi - lo;
    }
};
