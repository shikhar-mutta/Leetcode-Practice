// Link: https://leetcode.com/problems/maximum-performance-of-a-team/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return efficiency[a] > efficiency[b]; });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long speedSum = 0, best = 0;

        for (int i : idx) {
            minHeap.push(speed[i]);
            speedSum += speed[i];
            if ((int)minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            best = max(best, speedSum * efficiency[i]);
        }
        return (int)(best % MOD);
    }
};
