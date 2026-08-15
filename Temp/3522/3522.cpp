// Link: https://leetcode.com/problems/calculate-score-after-performing-instructions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false);
        long long score = 0;
        int idx = 0;
        while (idx >= 0 && idx < n && !visited[idx]) {
            visited[idx] = true;
            if (instructions[idx] == "add") {
                score += values[idx];
                idx++;
            } else {
                idx += values[idx];
            }
        }
        return score;
    }
};
