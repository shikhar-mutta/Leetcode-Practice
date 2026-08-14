// Link: https://leetcode.com/problems/earliest-second-to-mark-indices-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        vector<int> firstOcc(n + 1, -1);
        for (int i = 0; i < m; i++) if (firstOcc[changeIndices[i]] == -1) firstOcc[changeIndices[i]] = i;

        auto feasible = [&](int T) -> bool {
            long long cost = n; // marking seconds
            vector<pair<int,int>> resetCand; // (position, val)
            for (int idx = 1; idx <= n; idx++) {
                int val = nums[idx-1];
                if (val == 0) continue;
                bool hasOcc = (firstOcc[idx] != -1 && firstOcc[idx] < T);
                if (hasOcc && val >= 2) { cost += 1; resetCand.push_back({firstOcc[idx], val}); }
                else cost += val;
            }
            if (cost > T) return false;

            // resolve scheduling conflicts: repeatedly drop the least-beneficial
            // reset among those causing a Hall's-condition violation
            while (true) {
                sort(resetCand.begin(), resetCand.end());
                int K = resetCand.size();
                int violationStart = -1;
                for (int j = 0; j < K; j++) {
                    long long required = 2LL * K - 2LL * j + resetCand[j].first;
                    if (T < required) { violationStart = j; break; }
                }
                if (violationStart == -1) return true;
                // among candidates[violationStart..K-1], remove the one with smallest val (least savings)
                int removeIdx = violationStart;
                for (int j = violationStart + 1; j < K; j++)
                    if (resetCand[j].second < resetCand[removeIdx].second) removeIdx = j;
                cost += resetCand[removeIdx].second - 1; // convert to manual
                if (cost > T) return false;
                resetCand.erase(resetCand.begin() + removeIdx);
            }
        };

        int lo = n, hi = m, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    }
};
