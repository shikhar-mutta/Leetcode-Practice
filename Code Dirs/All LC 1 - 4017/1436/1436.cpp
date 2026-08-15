// Link: https://leetcode.com/problems/destination-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starts;
        for (auto& p : paths) starts.insert(p[0]);
        for (auto& p : paths) {
            if (!starts.count(p[1])) return p[1];
        }
        return "";
    }
};
