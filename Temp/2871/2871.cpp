// Link: https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int cur = -1, cnt = 0;
        for (int x : nums) {
            cur &= x;
            if (cur == 0) { cnt++; cur = -1; }
        }
        return max(cnt, 1);
    }
};
