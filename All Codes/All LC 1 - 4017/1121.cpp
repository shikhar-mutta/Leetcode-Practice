// Link: https://leetcode.com/problems/divide-array-into-increasing-sequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int n = nums.size();
        int maxFreq = 1, curFreq = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) curFreq++;
            else curFreq = 1;
            maxFreq = max(maxFreq, curFreq);
        }
        return (long long)maxFreq * k <= n;
    }
};
