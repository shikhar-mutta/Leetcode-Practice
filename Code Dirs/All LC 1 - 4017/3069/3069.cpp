// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a = {nums[0]}, b = {nums[1]};
        for (int i = 2; i < (int)nums.size(); i++) {
            if (a.back() > b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for (int x : b) a.push_back(x);
        return a;
    }
};
