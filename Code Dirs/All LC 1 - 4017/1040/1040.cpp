// Link: https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);

        int minMoves = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (stones[right] - stones[left] >= n) left++;
            int covered = right - left + 1;
            int cost;
            if (covered == n - 1 && stones[right] - stones[left] == n - 2) {
                cost = 2;
            } else {
                cost = n - covered;
            }
            minMoves = min(minMoves, cost);
        }
        return {minMoves, maxMoves};
    }
};
