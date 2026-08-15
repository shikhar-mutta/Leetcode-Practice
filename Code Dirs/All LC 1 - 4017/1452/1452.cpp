// Link: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        vector<unordered_set<string>> sets(n);
        for (int i = 0; i < n; i++) sets[i] = unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end());

        vector<int> res;
        for (int i = 0; i < n; i++) {
            bool isSubset = false;
            for (int j = 0; j < n; j++) {
                if (i == j || sets[j].size() < sets[i].size()) continue;
                bool allFound = true;
                for (auto& c : sets[i]) {
                    if (!sets[j].count(c)) { allFound = false; break; }
                }
                if (allFound && sets[j].size() > sets[i].size()) { isSubset = true; break; }
            }
            if (!isSubset) res.push_back(i);
        }
        return res;
    }
};
