// Link: https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        long long totalNeeded = 0;
        for (int x : nums) totalNeeded += x;

        auto feasible = [&](int T) -> bool {
            vector<int> lastOcc(n + 1, -1);
            for (int i = 0; i < T; i++) lastOcc[changeIndices[i]] = i;
            for (int idx = 1; idx <= n; idx++) if (lastOcc[idx] == -1) return false;

            vector<pair<int,int>> byDeadline;
            for (int idx = 1; idx <= n; idx++) byDeadline.push_back({lastOcc[idx], nums[idx-1]});
            sort(byDeadline.begin(), byDeadline.end());

            long long available = 0;
            int prev = -1;
            for (auto& [d, need] : byDeadline) {
                available += (d - prev - 1);
                if (available < need) return false;
                available -= need;
                prev = d;
            }
            return true;
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
