// Link: https://leetcode.com/problems/find-the-most-common-response/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total responses * log) SC: O(unique responses)
// Approach: dedupe each day's responses (a response counts at most once
// per day), tally frequencies across all days, and return the response
// with the highest total count, breaking ties lexicographically smallest.
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> count;
        for (auto& day : responses) {
            unordered_set<string> uniq(day.begin(), day.end());
            for (auto& r : uniq) count[r]++;
        }

        string best;
        int bestCount = -1;
        for (auto& [r, c] : count) {
            if (c > bestCount || (c == bestCount && r < best)) {
                best = r;
                bestCount = c;
            }
        }
        return best;
    }
};
