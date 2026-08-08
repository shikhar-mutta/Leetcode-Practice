// Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> pos;
        for (int i = 0; i < (int)target.size(); i++) pos[target[i]] = i;

        vector<int> seq;
        for (int x : arr) {
            if (!pos.count(x)) continue;
            int idx = pos[x];
            auto it = lower_bound(seq.begin(), seq.end(), idx);
            if (it == seq.end()) seq.push_back(idx);
            else *it = idx;
        }
        return target.size() - seq.size();
    }
};
