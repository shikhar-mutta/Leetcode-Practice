// Link: https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m log m), SC: O(n)
// Approach: Binary search on the answer second s. check(s) verifies every
// index 1..n has a change occurrence within [0,s) and simulates: seconds
// where changeIndices[i] isn't that index's LAST occurrence add +1 to power;
// at an index's last occurrence, decrementing must be affordable
// (power >= nums[idx-1]) to mark it. Feasible iff all n indices get marked.
class Solution {
public:
    bool check(int s, const vector<int>& nums,
               const vector<int>& changeIndices) {
        int n = nums.size();
        vector<int> lastOccurrence(n + 1, -1);

        for (int i = 0; i < s; ++i) {
            lastOccurrence[changeIndices[i]] = i;
        }

        for (int i = 1; i <= n; ++i) {
            if (lastOccurrence[i] == -1) {
                return false;
            }
        }

        long long power = 0;
        int markedCount = 0;

        for (int i = 0; i < s; ++i) {
            int idx = changeIndices[i];

            if (i == lastOccurrence[idx]) {
                if (power < nums[idx - 1]) {
                    return false;
                }
                power -= nums[idx - 1];
                markedCount++;
            } else {
                power++;
            }
        }

        return markedCount == n;
    }

    int earliestSecondToMarkIndices(vector<int>& nums,
                                    vector<int>& changeIndices) {
        int m = changeIndices.size();
        int low = 1, high = m;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, changeIndices)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
