// Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto &q : queries) {
            bool found = false;
            for (auto &d : dictionary) {
                int diff = 0;
                for (int i = 0; i < (int)q.size(); i++)
                    if (q[i] != d[i]) diff++;
                if (diff <= 2) { found = true; break; }
            }
            if (found) ans.push_back(q);
        }
        return ans;
    }
};
