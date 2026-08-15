// Link: https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int MAXV = 1000001;
        vector<int> spf(MAXV, 0);
        for (int i = 2; i < MAXV; i++) {
            if (spf[i] == 0) {
                for (long long j = i; j < MAXV; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        int n = nums.size();
        int ops = 0;
        long long maxAllowed = LLONG_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= maxAllowed) {
                maxAllowed = nums[i];
            } else {
                int p = spf[nums[i]];
                if (p <= maxAllowed) {
                    ops++;
                    maxAllowed = p;
                } else {
                    return -1;
                }
            }
        }
        return ops;
    }
};
