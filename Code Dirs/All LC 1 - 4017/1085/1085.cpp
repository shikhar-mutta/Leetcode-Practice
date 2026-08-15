// Link: https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int sum = 0;
        while (mn > 0) { sum += mn % 10; mn /= 10; }
        return sum % 2 == 0 ? 1 : 0;
    }
};
