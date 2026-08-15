// Link: https://leetcode.com/problems/find-the-most-common-response/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;
        for (auto& row : responses) {
            unordered_set<string> uniq(row.begin(), row.end());
            for (const string& s : uniq) freq[s]++;
        }
        string best;
        int bestCount = -1;
        for (auto& [s, c] : freq) {
            if (c > bestCount || (c == bestCount && s < best)) {
                bestCount = c;
                best = s;
            }
        }
        return best;
    }
};
