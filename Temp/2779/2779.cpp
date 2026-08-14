// Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (nums[right] - nums[left] > 2 * k) left++;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
