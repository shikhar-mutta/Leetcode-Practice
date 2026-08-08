// Link: https://leetcode.com/problems/search-suggestions-system/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix;
        for (char c : searchWord) {
            prefix += c;
            vector<string> matches;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for (int i = 0; i < 3 && it != products.end() && (*it).compare(0, prefix.size(), prefix) == 0; i++, ++it) {
                matches.push_back(*it);
            }
            res.push_back(matches);
        }
        return res;
    }
};
