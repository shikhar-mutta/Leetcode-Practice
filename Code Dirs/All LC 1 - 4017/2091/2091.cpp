// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int i = min(minIdx, maxIdx), j = max(minIdx, maxIdx);
        int fromFront = j + 1;
        int fromBack = n - i;
        int both = (i + 1) + (n - j);
        return min({fromFront, fromBack, both});
    }
};
