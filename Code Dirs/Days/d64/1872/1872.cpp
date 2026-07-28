// Link: https://leetcode.com/problems/stone-game-viii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: any move reduces to picking prefix sum prefix[i] for i>=1 (taking
// the first i stones). best[i] = max(prefix[i], best[i+1] - prefix[i]) computed
// from the back, representing optimal value when choice starts at index i.
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + stones[i];

        long long best = prefix[n-1];
        for (int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }
        return (int)best; // best already folds in the "skip" option each step
    }
};
