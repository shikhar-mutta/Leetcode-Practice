// Link: https://leetcode.com/problems/frog-jump-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if (n == 2) return stones[1] - stones[0];
        int best = 0;
        for (int i = 2; i < n; i++)
            best = max(best, stones[i] - stones[i-2]);
        best = max(best, stones[1] - stones[0]);
        best = max(best, stones[n-1] - stones[n-2]);
        return best;
    }
};
