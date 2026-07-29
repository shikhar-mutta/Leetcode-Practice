// Link: https://leetcode.com/problems/find-the-most-common-response/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int> count;
        for (auto& r : responses) {
            set<string> uniq(r.begin(), r.end());
            for (auto& s : uniq) count[s]++;
        }

        string best;
        int bestCount = -1;
        for (auto& [s, c] : count) {
            if (c > bestCount) {
                bestCount = c;
                best = s;
            }
        }
        return best;
    }
};
