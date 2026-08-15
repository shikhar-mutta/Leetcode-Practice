// Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            int count = 0;
            for (int v : nums) if (v >= x) count++;
            if (count == x) return x;
        }
        return -1;
    }
};
