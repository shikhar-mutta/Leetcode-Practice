// Link: https://leetcode.com/problems/find-mirror-score-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> stacks(26);
        long long score = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            int mirror = 'z' - s[i];
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
