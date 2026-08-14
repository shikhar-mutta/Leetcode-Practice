// Link: https://leetcode.com/problems/house-robber-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto countRobbable = [&](int cap) {
            int count = 0;
            int i = 0, n = nums.size();
            while (i < n) {
                if (nums[i] <= cap) { count++; i += 2; }
                else i++;
            }
            return count;
        };

        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countRobbable(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
