// Link: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: zero out smallest values first, then next smallest, etc.
// Two equal values separated by a smaller value need separate operations
// (the smaller one gets zeroed first, breaking the subarray). Maintain a
// monotonically increasing stack of distinct nonzero values seen; when
// x is smaller than the top, pop (that popped value needs its own
// operation) until the stack fits x, then push x if it's nonzero and
// not already on top (duplicates adjacent through only-larger values
// share one future operation). Remaining stack entries at the end each
// need one more operation.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stk;
        int ans = 0;
        for (int x : nums) {
            while (!stk.empty() && stk.back() > x) {
                ans++;
                stk.pop_back();
            }
            if (x != 0 && (stk.empty() || stk.back() != x)) stk.push_back(x);
        }
        ans += stk.size();
        return ans;
    }
};
