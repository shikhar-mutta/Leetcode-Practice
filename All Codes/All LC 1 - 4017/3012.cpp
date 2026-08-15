// Link: https://leetcode.com/problems/minimize-length-of-array-using-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n), SC: O(1)
// Approach: Let m = min(nums). Any element not divisible by m collapses the
// whole array to length 1 (mod-repeatedly with m). Otherwise only pairs of
// the minimum value can shrink further, so answer = ceil(count(m)/2).
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());

        for (int x : nums)
            if (x % m != 0) return 1;

        int cnt = 0;
        for (int x : nums)
            if (x == m) cnt++;

        return (cnt + 1) / 2;
    }
};
