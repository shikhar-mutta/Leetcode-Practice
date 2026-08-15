// Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> need;
        for (int i = 0; i < (int)recipes.size(); i++) {
            need[recipes[i]] = ingredients[i].size();
            for (auto& ing : ingredients[i]) graph[ing].push_back(recipes[i]);
        }
        queue<string> q;
        for (auto& s : supplies) q.push(s);
        vector<string> res;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (auto& recipe : graph[cur]) {
                if (--need[recipe] == 0) {
                    res.push_back(recipe);
                    q.push(recipe);
                }
            }
        }
        return res;
    }
};
