// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        vector<int> stack;
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!stack.empty() && stack.back() < heights[i]) {
                stack.pop_back();
                count++;
            }
            if (!stack.empty()) count++;
            res[i] = count;
            stack.push_back(heights[i]);
        }
        return res;
    }
};
