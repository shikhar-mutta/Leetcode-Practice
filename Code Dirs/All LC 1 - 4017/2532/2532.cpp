// Link: https://leetcode.com/problems/time-to-cross-a-bridge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto eff = [&](int i) { return time[i][0] + time[i][2]; };
        // "less efficient" = larger eff, or equal eff and larger index.
        // We want the top of the priority_queue to be the LEAST efficient worker.
        auto cmp = [&](int a, int b) {
            // returns true if a has LOWER priority than b (a is more efficient than b)
            if (eff(a) != eff(b)) return eff(a) < eff(b);
            return a < b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> waitLeft(cmp), waitRight(cmp);
        for (int i = 0; i < k; i++) waitLeft.push(i);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> picking, putting;

        long long bridgeFreeAt = 0;
        int pending = n;
        int delivered = 0;
        long long answer = 0;

        while (delivered < n) {
            while (!picking.empty() && picking.top().first <= bridgeFreeAt) {
                waitRight.push(picking.top().second);
                picking.pop();
            }
            while (!putting.empty() && putting.top().first <= bridgeFreeAt) {
                waitLeft.push(putting.top().second);
                putting.pop();
            }

            if (!waitRight.empty()) {
                int w = waitRight.top(); waitRight.pop();
                long long finishCross = bridgeFreeAt + time[w][2];
                bridgeFreeAt = finishCross;
                putting.push({finishCross + time[w][3], w});
                delivered++;
                answer = finishCross;
            } else if (!waitLeft.empty() && pending > 0) {
                int w = waitLeft.top(); waitLeft.pop();
                pending--;
                long long finishCross = bridgeFreeAt + time[w][0];
                bridgeFreeAt = finishCross;
                picking.push({finishCross + time[w][1], w});
            } else {
                long long nextEvent = LLONG_MAX;
                if (!picking.empty()) nextEvent = min(nextEvent, picking.top().first);
                if (!putting.empty()) nextEvent = min(nextEvent, putting.top().first);
                bridgeFreeAt = nextEvent;
            }
        }
        return (int)answer;
    }
};
