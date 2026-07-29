// Link: https://leetcode.com/problems/put-marbles-in-bags/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: any split's total score = weights[0]+weights[n-1] + sum of pairSum(i)=w[i]+w[i+1]
// at the k-1 chosen cut points. Max-min difference = (sum of k-1 largest pairSums) - (sum of
// k-1 smallest pairSums), independent of the fixed endpoint terms.
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;
        vector<int> pairSum(n-1);
        for (int i = 0; i < n-1; i++) pairSum[i] = weights[i] + weights[i+1];
        sort(pairSum.begin(), pairSum.end());

        long long maxScore = 0, minScore = 0;
        for (int i = 0; i < k-1; i++) minScore += pairSum[i];
        for (int i = 0; i < k-1; i++) maxScore += pairSum[n-2-i];
        return maxScore - minScore;
    }
};
