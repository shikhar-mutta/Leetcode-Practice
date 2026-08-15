// Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        vector<pair<char,char>> combos = {{'N','E'}, {'N','W'}, {'S','E'}, {'S','W'}};
        int best = 0;
        for (auto& [vt, ht] : combos) {
            int cur = 0, rem = k;
            for (char c : s) {
                if (c == vt || c == ht) cur++;
                else if (rem > 0) { cur++; rem--; }
                else cur--;
                best = max(best, cur);
            }
        }
        return best;
    }
};
