// Link: https://leetcode.com/problems/put-marbles-in-bags/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;
        vector<int> pairSums;
        for (int i = 0; i + 1 < n; i++) pairSums.push_back(weights[i] + weights[i+1]);
        sort(pairSums.begin(), pairSums.end());

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSums[i];
            maxSum += pairSums[pairSums.size() - 1 - i];
        }
        return maxSum - minSum;
    }
};
