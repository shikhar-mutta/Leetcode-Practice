// Link: https://leetcode.com/problems/count-pairs-in-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; i++) diff[i] = nums1[i] - nums2[i];
        sort(diff.begin(), diff.end());

        long long count = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (diff[left] + diff[right] > 0) {
                count += right - left;
                right--;
            } else {
                left++;
            }
        }
        return count;
    }
};
