// Link: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res(n);
        int mid = (n + 1) / 2;
        int lo = 0, hi = mid;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) res[i] = nums[lo++];
            else res[i] = nums[hi++];
        }
        return res;
    }
};
