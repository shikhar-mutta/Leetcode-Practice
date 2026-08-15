// Link: https://leetcode.com/problems/sum-of-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            bool isGood = true;
            if ((i - k >= 0 && !(nums[i - k] < nums[i])))
                isGood = false;
            if ((i + k < n && !(nums[i + k] < nums[i])))
                isGood = false;
            if (isGood)
                sum += nums[i];
        }
        return sum;
    }
};
