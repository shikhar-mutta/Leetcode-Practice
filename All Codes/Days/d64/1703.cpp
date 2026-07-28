// Link: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long long> pos;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] == 1) pos.push_back(i);
        int m = pos.size();
        vector<long long> g(m);
        for (int i = 0; i < m; i++) g[i] = pos[i] - i;
        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) prefix[i+1] = prefix[i] + g[i];
        long long best = LLONG_MAX;
        for (int i = 0; i + k <= m; i++) {
            int mid = i + k / 2;
            long long medVal = g[mid];
            long long leftCount = mid - i;
            long long leftSum = prefix[mid] - prefix[i];
            long long leftCost = medVal * leftCount - leftSum;
            long long rightCount = (i + k) - mid - 1;
            long long rightSum = prefix[i+k] - prefix[mid+1];
            long long rightCost = rightSum - medVal * rightCount;
            best = min(best, leftCost + rightCost);
        }
        return (int)best;
    }
};
