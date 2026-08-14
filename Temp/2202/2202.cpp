// Link: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int limit = min(k, n);
        int best = -1;
        for (int m = 0; m <= limit; m++) {
            int leftover = k - m;
            if (leftover % 2 == 0) {
                if (m < n) best = max(best, nums[m]);
            } else {
                if (m >= 1) best = max(best, nums[m - 1]);
            }
        }
        return best;
    }
};
