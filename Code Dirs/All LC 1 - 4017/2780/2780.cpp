// Link: https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) { candidate = x; count = 1; }
            else if (x == candidate) count++;
            else count--;
        }

        int totalCount = 0;
        for (int x : nums) if (x == candidate) totalCount++;

        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) leftCount++;
            int leftLen = i + 1;
            int rightLen = n - leftLen;
            int rightCount = totalCount - leftCount;
            if (leftCount * 2 > leftLen && rightCount * 2 > rightLen) return i;
        }
        return -1;
    }
};
