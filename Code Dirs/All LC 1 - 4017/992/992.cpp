// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int,int> cnt;
        int left = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            cnt[nums[right]]++;
            while ((int)cnt.size() > k) {
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) cnt.erase(nums[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
