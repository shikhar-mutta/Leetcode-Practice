// Link: https://leetcode.com/problems/time-to-cross-a-bridge/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+K) log K), SC: O(K)
// Approach: event simulation with 4 structures — max-heaps (by efficiency=right+left, then
// index desc) for workers waiting on each bank, min-heaps (by finish time) for workers busy
// picking/putting. Right-bank waiters always get bridge priority over left-bank waiters.
// If the bridge is idle with no one waiting, fast-forward time to the next finishing worker.
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int,int>> waitR, waitL; // (efficiency, idx) ready to cross
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> workR, workL; // (finishTime, idx)

        for (int i = 0; i < k; i++) waitR.push({time[i][0] + time[i][2], i});

        long long t = 0;
        long long ans = 0;

        while (n > 0 || !workR.empty() || !waitL.empty() || !workL.empty()) {
            while (!workR.empty() && workR.top().first <= t) {
                int idx = workR.top().second; workR.pop();
                waitL.push({time[idx][0] + time[idx][2], idx});
            }
            while (!workL.empty() && workL.top().first <= t) {
                int idx = workL.top().second; workL.pop();
                waitR.push({time[idx][0] + time[idx][2], idx});
            }

            if (!waitL.empty()) {
                int idx = waitL.top().second; waitL.pop();
                t += time[idx][2];
                ans = max(ans, t);
                workL.push({t + time[idx][3], idx});
            } else if (!waitR.empty() && n > 0) {
                int idx = waitR.top().second; waitR.pop();
                n--;
                t += time[idx][0];
                workR.push({t + time[idx][1], idx});
            } else {
                long long next = LLONG_MAX;
                if (!workR.empty()) next = min(next, (long long)workR.top().first);
                if (!workL.empty()) next = min(next, (long long)workL.top().first);
                t = next;
            }
        }
        return (int)ans;
    }
};
