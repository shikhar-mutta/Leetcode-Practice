// Link: https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string cur;
        for (char target_c : target) {
            cur += 'a';
            res.push_back(cur);
            for (char c = 'a'; c < target_c; c++) {
                cur.back()++;
                res.push_back(cur);
            }
        }
        return res;
    }
};
