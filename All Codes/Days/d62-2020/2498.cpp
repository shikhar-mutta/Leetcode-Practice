// Link: https://leetcode.com/problems/frog-jump-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: the optimal strategy alternates forward and back jumps by
// splitting the stones into two interleaved chains (one visited going
// forward to the last stone, one visited coming back to the first),
// which is equivalent to jumping stone i to stone i+2 for each parity
// group. So the minimized maximum jump is just the largest gap between
// stones two apart, except for the very first jump (stone 0 to stone 1),
// which is unavoidable since the frog must leave the bank.
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int res = stones[1] - stones[0]; // the unavoidable first jump

        for (int i = 2; i < n; ++i)
            res = max(res, stones[i] - stones[i - 2]);

        return res;
    }
};
