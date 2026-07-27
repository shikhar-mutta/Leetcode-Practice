// Link: https://leetcode.com/problems/find-mirror-score-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: keep a stack of unused indices per letter. For each index i,
// look up the stack for its mirror letter ('a'<->'z', 'b'<->'y', ...); if
// non-empty, pop the closest previous unused occurrence, add the index
// gap to the score, and consume both. Otherwise push i onto its own
// letter's stack to be matched later.
class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> stacks(26);
        long long score = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            int mirror = 25 - c;
            if (!stacks[mirror].empty()) {
                int j = stacks[mirror].back();
                stacks[mirror].pop_back();
                score += i - j;
            } else {
                stacks[c].push_back(i);
            }
        }
        return score;
    }
};
