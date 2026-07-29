// Link: https://leetcode.com/problems/partition-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;
        string cur = "";
        for (char c : s) {
            cur += c;
            if (!seen.count(cur)) {
                seen.insert(cur);
                result.push_back(cur);
                cur = "";
            }
        }
        return result;
    }
};
