// Link: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> cum(n, 0);
        for (int k = 1; k < n; k++)
            cum[k] = cum[k-1] + (boxes[k][0] != boxes[k-1][0] ? 1 : 0);

        vector<long long> dp(n + 1, 0);
        deque<int> dq;
        dq.push_back(0);

        int left = 0;
        long long weightSum = 0;
        for (int i = 1; i <= n; i++) {
            int boxIdx = i - 1;
            weightSum += boxes[boxIdx][1];
            while ((i - left) > maxBoxes || weightSum > maxWeight) {
                weightSum -= boxes[left][1];
                left++;
            }
            while (!dq.empty() && dq.front() < left) dq.pop_front();

            dp[i] = dp[dq.front()] - cum[dq.front()] + 2 + cum[boxIdx];

            if (i < n) {
                long long val = dp[i] - cum[i];
                while (!dq.empty() && (dp[dq.back()] - cum[dq.back()]) >= val) dq.pop_back();
                dq.push_back(i);
            }
        }
        return (int)dp[n];
    }
};
