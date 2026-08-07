// Link: https://leetcode.com/problems/group-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k log k)  SC: O(n * k)
// Approach: hash map keyed by sorted string, group original strings sharing a key
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : groups) res.push_back(v);
        return res;
    }
};
