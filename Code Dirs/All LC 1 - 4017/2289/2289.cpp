// Link: https://leetcode.com/problems/steps-to-make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<pair<int,int>> stk; // value, steps
        int answer = 0;
        for (int num : nums) {
            int maxSteps = 0;
            while (!stk.empty() && stk.back().first <= num) {
                maxSteps = max(maxSteps, stk.back().second);
                stk.pop_back();
            }
            int steps = stk.empty() ? 0 : maxSteps + 1;
            stk.push_back({num, steps});
            answer = max(answer, steps);
        }
        return answer;
    }
};
