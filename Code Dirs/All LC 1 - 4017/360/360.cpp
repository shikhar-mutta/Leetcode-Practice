// Link: https://leetcode.com/problems/sort-transformed-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: quadratic values form a parabola; fill result from the correct
// end (largest values at ends if a>0, at center if a<0) via two-pointer merge
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        int idx = a >= 0 ? n - 1 : 0;
        auto f = [&](int x) { return a * x * x + b * x + c; };

        while (l <= r) {
            int fl = f(nums[l]), fr = f(nums[r]);
            if (a >= 0) {
                if (fl > fr) { res[idx--] = fl; l++; }
                else { res[idx--] = fr; r--; }
            } else {
                if (fl < fr) { res[idx++] = fl; l++; }
                else { res[idx++] = fr; r--; }
            }
        }
        return res;
    }
};
