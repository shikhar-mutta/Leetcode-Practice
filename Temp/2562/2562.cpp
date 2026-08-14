// Link: https://leetcode.com/problems/find-the-array-concatenation-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        long long total = 0;
        while (lo < hi) {
            string s = to_string(nums[lo]) + to_string(nums[hi]);
            total += stoll(s);
            lo++; hi--;
        }
        if (lo == hi) total += nums[lo];
        return total;
    }
};
