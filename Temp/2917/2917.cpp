// Link: https://leetcode.com/problems/find-the-k-or-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int b = 0; b < 32; b++) {
            int cnt = 0;
            for (int x : nums) if (x & (1 << b)) cnt++;
            if (cnt >= k) ans |= (1 << b);
        }
        return ans;
    }
};
