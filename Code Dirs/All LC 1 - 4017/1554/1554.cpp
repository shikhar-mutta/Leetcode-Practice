// Link: https://leetcode.com/problems/strings-differ-by-one-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int n = dict.size(), m = dict[0].size();
        for (int j = 0; j < m; j++) {
            unordered_set<string> seen;
            for (auto& s : dict) {
                string key = s.substr(0, j) + '*' + s.substr(j + 1);
                if (seen.count(key)) return true;
                seen.insert(key);
            }
        }
        return false;
    }
};
