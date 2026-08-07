// Link: https://leetcode.com/problems/encode-and-decode-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total length)  SC: O(total length)
// Approach: length-prefix each string as "len#str" — a length-prefixed scheme sidesteps any
// ambiguity from delimiter characters appearing inside the strings themselves
class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) res += to_string(s.size()) + "#" + s;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};
