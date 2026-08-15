// Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foodSet;
        map<int, map<string,int>> tables;
        for (auto& o : orders) {
            int table = stoi(o[1]);
            string food = o[2];
            foodSet.insert(food);
            tables[table][food]++;
        }

        vector<string> foods(foodSet.begin(), foodSet.end());
        vector<vector<string>> res;

        vector<string> header;
        header.push_back("Table");
        for (auto& f : foods) header.push_back(f);
        res.push_back(header);

        for (auto& [table, foodCounts] : tables) {
            vector<string> row;
            row.push_back(to_string(table));
            for (auto& f : foods) {
                int c = foodCounts.count(f) ? foodCounts[f] : 0;
                row.push_back(to_string(c));
            }
            res.push_back(row);
        }
        return res;
    }
};
