// Link: https://leetcode.com/problems/merge-similar-items/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> total;
        for (auto& it : items1) total[it[0]] += it[1];
        for (auto& it : items2) total[it[0]] += it[1];
        vector<vector<int>> res;
        for (auto& [v, w] : total) res.push_back({v, w});
        return res;
    }
};
