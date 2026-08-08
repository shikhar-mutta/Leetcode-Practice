// Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a > b;
        });
        return nums[k-1];
    }
};
