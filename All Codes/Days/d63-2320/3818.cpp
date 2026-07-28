// Link: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: find the longest strictly increasing suffix by scanning
// from the right and extending while nums[i] < nums[i+1]; the answer is
// n minus that suffix's length (remove everything before it).
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) len++;
            else break;
        }
        return n - len;
    }
};
