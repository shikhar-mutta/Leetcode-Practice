// Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int> res;
        for (int x : nums) {
            int idx = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
            res.push_back(idx);
        }
        return res;
    }
};
