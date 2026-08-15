// Link: https://leetcode.com/problems/sort-features-by-popularity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> count;
        for (auto& f : features) count[f] = 0;

        for (auto& r : responses) {
            unordered_set<string> seen;
            stringstream ss(r);
            string word;
            while (ss >> word) {
                if (count.count(word) && !seen.count(word)) {
                    count[word]++;
                    seen.insert(word);
                }
            }
        }

        int n = features.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
            return count[features[a]] > count[features[b]];
        });

        vector<string> res;
        for (int i : idx) res.push_back(features[i]);
        return res;
    }
};
