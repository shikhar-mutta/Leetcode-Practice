// Link: https://leetcode.com/problems/continuous-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window;
        int left = 0;
        long long count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
