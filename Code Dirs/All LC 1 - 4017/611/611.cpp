// Link: https://leetcode.com/problems/valid-triangle-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: sort; fix the largest side k, two-pointer i,j from both ends of [0,k-1] — if nums[i]+nums[j] > nums[k], all pairs from i..j-1 with j work, count j-i, decrement j; else increment i.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int k = n-1; k >= 2; k--) {
            int i = 0, j = k-1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += j - i;
                    j--;
                } else i++;
            }
        }
        return count;
    }
};
