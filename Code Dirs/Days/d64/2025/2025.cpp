// Link: https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: prefix sums. Without any change, count partition points i where
// prefix[i]*2==total. For each candidate changed index j with delta=k-nums[j],
// split partitions into those before/at j (need prefix[i]=(total+delta)/2)
// and those after j (need prefix[i]=(total-delta)/2), using two hashmaps of
// prefix-value counts that slide as j advances, giving O(n) total.
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
        long long total = prefix[n];

        int baseline = 0;
        for (int i = 1; i <= n - 1; i++) if (prefix[i] * 2 == total) baseline++;

        unordered_map<long long,int> leftCounts, rightCounts;
        for (int i = 1; i <= n - 1; i++) rightCounts[prefix[i]]++;

        int best = baseline;
        for (int j = 0; j < n; j++) {
            long long delta = (long long)k - nums[j];
            int cur = 0;
            long long targetRight2 = total - delta; // i>j branch: prefix[i] = (total-delta)/2
            if (targetRight2 % 2 == 0) {
                long long tv = targetRight2 / 2;
                auto it = rightCounts.find(tv);
                if (it != rightCounts.end()) cur += it->second;
            }
            long long targetLeft2 = total + delta; // i<=j branch: prefix[i] = (total+delta)/2
            if (targetLeft2 % 2 == 0) {
                long long tv = targetLeft2 / 2;
                auto it = leftCounts.find(tv);
                if (it != leftCounts.end()) cur += it->second;
            }
            best = max(best, cur);

            // slide: move prefix[j+1] from rightCounts to leftCounts for next iteration
            int nextIdx = j + 1;
            if (nextIdx >= 1 && nextIdx <= n - 1) {
                rightCounts[prefix[nextIdx]]--;
                leftCounts[prefix[nextIdx]]++;
            }
        }
        return best;
    }
};
