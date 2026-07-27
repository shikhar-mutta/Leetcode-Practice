// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: build the n+1 gaps around meetings. For each meeting i,
// removing it always lets its two neighboring gaps merge (worst case by
// just sliding meeting i to touch one side, gaining gap[i]+gap[i+1] with
// no capacity check needed). If some OTHER gap (not adjacent to i) is
// large enough to fully host meeting i's duration, the meeting can be
// moved entirely away instead, gaining the full gap[i]+dur[i]+gap[i+1].
// Track the top-3 largest gaps (by value) so, excluding indices i and
// i+1, we can always find a valid "other gap" candidate in O(1).
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1), dur(n);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) gaps[i] = startTime[i] - endTime[i-1];
        gaps[n] = eventTime - endTime[n-1];
        for (int i = 0; i < n; i++) dur[i] = endTime[i] - startTime[i];

        vector<pair<int,int>> top; // (value, index), sorted desc, keep top 3
        for (int i = 0; i <= n; i++) {
            top.push_back({gaps[i], i});
            sort(top.begin(), top.end(), greater<>());
            if (top.size() > 3) top.resize(3);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int bestExternal = -1;
            for (auto& [val, idx] : top) {
                if (idx != i && idx != i + 1) { bestExternal = val; break; }
            }
            int candidate;
            if (bestExternal >= dur[i]) candidate = gaps[i] + dur[i] + gaps[i+1];
            else candidate = gaps[i] + gaps[i+1];
            ans = max(ans, candidate);
        }
        return ans;
    }
};
