// Link: https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: monotonic decreasing stack of indices; when a warmer day is found, pop and resolve all cooler days on the stack.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[stk.back()] < temperatures[i]) {
                int j = stk.back(); stk.pop_back();
                res[j] = i - j;
            }
            stk.push_back(i);
        }
        return res;
    }
};
