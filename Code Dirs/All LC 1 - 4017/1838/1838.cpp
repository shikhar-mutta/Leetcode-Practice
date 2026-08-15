// Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long long sum = 0;
        int best = 1;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
