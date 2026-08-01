// Link: https://leetcode.com/problems/earliest-second-to-mark-indices-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m log m)  SC: O(n)
// Approach: binary search on the answer second s. check(s): every index
// 1..n must have an occurrence within the first s seconds (its LAST
// occurrence is where it must be marked). Simulate: at non-last
// occurrences, bank +1 "power" (spare decrement capacity, shared across
// all indices); at an index's last occurrence, spend power >= nums[idx-1]
// to mark it (must be affordable at that exact point). Feasible iff every
// index gets marked this way.
class Solution {
    bool check(int s, const vector<int>& nums, const vector<int>& changeIndices) {
        int n = nums.size();
        vector<int> lastOcc(n + 1, -1);
        for (int i = 0; i < s; i++) lastOcc[changeIndices[i]] = i;
        for (int i = 1; i <= n; i++) if (lastOcc[i] == -1) return false;
        long long power = 0;
        int marked = 0;
        for (int i = 0; i < s; i++) {
            int idx = changeIndices[i];
            if (i == lastOcc[idx]) {
                if (power < nums[idx - 1]) return false;
                power -= nums[idx - 1];
                marked++;
            } else {
                power++;
            }
        }
        return marked == n;
    }

public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();
        int lo = 1, hi = m, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums, changeIndices)) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    }
};
