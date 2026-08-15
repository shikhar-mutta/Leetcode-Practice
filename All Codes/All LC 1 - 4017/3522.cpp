// Link: https://leetcode.com/problems/calculate-score-after-performing-instructions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: simulate starting at index 0. "add" adds values[i] to the
// score and moves to i+1; "jump" moves to i+values[i] without changing
// score. Stop as soon as the index goes out of bounds or revisits an
// already-executed index (to avoid infinite loops).
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
