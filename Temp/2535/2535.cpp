// Link: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;
        for (int x : nums) {
            elementSum += x;
            while (x > 0) { digitSum += x % 10; x /= 10; }
        }
        return elementSum - digitSum;
    }
};
