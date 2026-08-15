// Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) sum += nums[i] * nums[i];
        }
        return sum;
    }
};
