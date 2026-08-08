// Link: https://leetcode.com/problems/binary-searchable-numbers-in-an-unsorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMin(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) prefixMax[i] = max(prefixMax[i-1], nums[i]);
        suffixMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) suffixMin[i] = min(suffixMin[i+1], nums[i]);

        int count = 0;
        for (int i = 0; i < n; i++) {
            bool leftOk = (i == 0) || (prefixMax[i-1] < nums[i]);
            bool rightOk = (i == n-1) || (suffixMin[i+1] > nums[i]);
            if (leftOk && rightOk) count++;
        }
        return count;
    }
};
