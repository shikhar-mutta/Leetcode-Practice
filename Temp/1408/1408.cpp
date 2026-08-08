// Link: https://leetcode.com/problems/string-matching-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (int i = 0; i < (int)words.size(); i++) {
            for (int j = 0; j < (int)words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
