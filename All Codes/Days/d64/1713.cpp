// Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> idx;
        for (int i = 0; i < (int)target.size(); i++) idx[target[i]] = i;
        vector<int> seq;
        for (int x : arr) {
            if (!idx.count(x)) continue;
            int v = idx[x];
            auto it = lower_bound(seq.begin(), seq.end(), v);
            if (it == seq.end()) seq.push_back(v);
            else *it = v;
        }
        return (int)target.size() - (int)seq.size();
    }
};
