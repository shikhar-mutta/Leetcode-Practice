// Link: https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);
        long long running = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            long long cur = nums[i] + running;
            if (cur < 0) return false;
            if (cur == 0) continue;
            if (i + k > n) return false;
            running -= cur;
            diff[i + k] += cur;
        }
        return true;
    }
};
