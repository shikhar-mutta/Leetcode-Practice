// Link: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> prefixWeight(n + 1, 0);
        vector<int> T(n + 2, 0); // T[i] = transitions among boxes[0..i-1]
        for (int i = 0; i < n; i++) {
            prefixWeight[i+1] = prefixWeight[i] + boxes[i][1];
            if (i == 0) T[i+1] = 0;
            else T[i+1] = T[i] + (boxes[i][0] != boxes[i-1][0] ? 1 : 0);
        }
        vector<long long> dp(n + 1, LLONG_MAX / 2);
        dp[0] = 0;
        T[n+1] = T[n];
        auto val = [&](int j) { return dp[j] - T[j + 1]; };
        deque<int> dq; // indices j, increasing dp[j]-T[j+1]
        dq.push_back(0);
        int left = 0;
        for (int i = 1; i <= n; i++) {
            // shrink window: box count constraint i-j<=maxBoxes, weight constraint
            while (i - left > maxBoxes || prefixWeight[i] - prefixWeight[left] > maxWeight) left++;
            while (!dq.empty() && dq.front() < left) dq.pop_front();
            long long best = val(dq.front());
            dp[i] = best + 2 + T[i];
            // push i as candidate for future
            long long v = val(i);
            while (!dq.empty() && val(dq.back()) >= v) dq.pop_back();
            dq.push_back(i);
        }
        return (int)dp[n];
    }
};
