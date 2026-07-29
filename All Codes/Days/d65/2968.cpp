// Link: https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: sort nums. For any contiguous window (after sorting, the optimal group to unify is
// always contiguous), the cheapest common value is the median, and the cost to equalize the
// window is computable in O(1) via prefix sums. Two-pointer: expand the right edge, shrink the
// left edge while cost exceeds k, track the max window length seen.
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        auto cost = [&](int l, int r) -> long long {
            int mid = (l + r) / 2;
            long long val = nums[mid];
            long long leftSum = val * (mid - l) - (prefix[mid] - prefix[l]);
            long long rightSum = (prefix[r+1] - prefix[mid+1]) - val * (r - mid);
            return leftSum + rightSum;
        };

        int l = 0, ans = 1;
        for (int r = 0; r < n; r++) {
            while (cost(l, r) > k) l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
