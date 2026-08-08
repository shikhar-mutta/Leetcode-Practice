// Link: https://leetcode.com/problems/special-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) SC: O(n)
// Approach: recursively split s into maximal special substrings (balance returns to 0 exactly at each split point); recursively make each substring's interior largest, wrap each with "1"+interior+"0", then sort all pieces descending and concatenate.
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;
        vector<string> pieces;
        int balance = 0, start = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            balance += (s[i] == '1') ? 1 : -1;
            if (balance == 0) {
                pieces.push_back("1" + makeLargestSpecial(s.substr(start+1, i-start-1)) + "0");
                start = i+1;
            }
        }
        sort(pieces.begin(), pieces.end(), greater<string>());
        string res;
        for (auto& p : pieces) res += p;
        return res;
    }
};
