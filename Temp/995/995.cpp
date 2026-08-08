// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int curFlip = 0, res = 0;
        for (int i = 0; i < n; i++) {
            curFlip += diff[i];
            int cur = (nums[i] + curFlip) % 2;
            if (cur == 0) {
                if (i + k > n) return -1;
                res++;
                curFlip++;
                diff[i + k]--;
            }
        }
        return res;
    }
};
