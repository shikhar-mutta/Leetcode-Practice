// Link: https://leetcode.com/problems/rank-transform-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        unordered_map<int,int> rank;
        for (int i = 0; i < (int)sorted.size(); i++) rank[sorted[i]] = i + 1;
        vector<int> res;
        for (int x : arr) res.push_back(rank[x]);
        return res;
    }
};
