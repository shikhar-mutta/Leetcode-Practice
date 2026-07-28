// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: monotonic decreasing stack from right to left. Pop everyone
// shorter than the current person (each popped person is visible), and if
// the stack isn't empty after popping, the remaining taller person is also
// visible (blocks further view).
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!stk.empty() && stk.back() < heights[i]) {
                stk.pop_back();
                cnt++;
            }
            if (!stk.empty()) cnt++;
            res[i] = cnt;
            stk.push_back(heights[i]);
        }
        return res;
    }
};
