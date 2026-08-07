// Link: https://leetcode.com/problems/group-shifted-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(n*k)
// Approach: hash map keyed by the string's shift-invariant signature (each char's difference from
// the first char, mod 26), group original strings sharing a key
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        for (auto& s : strings) {
            string key;
            for (char c : s) key += (char)(((c - s[0]) + 26) % 26 + 'a');
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : groups) res.push_back(v);
        return res;
    }
};
