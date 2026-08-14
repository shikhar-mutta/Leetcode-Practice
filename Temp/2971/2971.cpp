// Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        for (int x : nums) sum += x;
        for (int i = n - 1; i >= 2; i--) {
            sum -= nums[i];
            if (sum > nums[i]) return sum + nums[i];
        }
        return -1;
    }
};
