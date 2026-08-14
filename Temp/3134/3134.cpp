// Link: https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countLE(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l = 0;
        long long cnt = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            freq[nums[r]]++;
            while ((int)freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;
        long long medianPos = (total + 1) / 2;

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(nums, mid) >= medianPos) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
