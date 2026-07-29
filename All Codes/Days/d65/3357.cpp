// Link: https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: gaps of -1 bounded by two known values L,R over g positions can always be filled
// with an even ramp achieving max-step = ceil(|L-R|/(g+1)), which is provably optimal for that
// segment. Gaps open on one side (or the whole array unknown) impose no constraint — freely
// fillable with a flat or monotonic run for any target. So the answer is just the max of that
// ceil formula over every two-sided gap (plus any already-fixed adjacent diffs).
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (nums[i] != -1) {
                if (i+1 < n && nums[i+1] != -1) ans = max(ans, abs(nums[i+1] - nums[i]));
                i++;
                continue;
            }
            int j = i;
            while (j < n && nums[j] == -1) j++;
            int g = j - i;
            if (i > 0 && j < n) {
                long long diff = abs((long long)nums[j] - nums[i-1]);
                long long need = (diff + g) / (g + 1); // ceil(diff/(g+1))
                ans = max(ans, (int)need);
            }
            i = j;
        }
        return ans;
    }
};
