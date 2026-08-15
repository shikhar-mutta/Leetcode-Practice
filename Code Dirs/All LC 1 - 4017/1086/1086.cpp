// Link: https://leetcode.com/problems/high-five/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> scores;
        for (auto& it : items) scores[it[0]].push_back(it[1]);

        vector<vector<int>> res;
        for (auto& [id, v] : scores) {
            sort(v.rbegin(), v.rend());
            int sum = 0;
            for (int i = 0; i < 5; i++) sum += v[i];
            res.push_back({id, sum / 5});
        }
        return res;
    }
};
