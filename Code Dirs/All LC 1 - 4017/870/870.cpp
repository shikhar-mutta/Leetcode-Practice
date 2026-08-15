// Link: https://leetcode.com/problems/advantage-shuffle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums2[a] < nums2[b]; });

        vector<int> res(n);
        int lo = 0, hi = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int j = idx[i];
            if (nums1[hi] > nums2[j]) {
                res[j] = nums1[hi];
                hi--;
            } else {
                res[j] = nums1[lo];
                lo++;
            }
        }
        return res;
    }
};
