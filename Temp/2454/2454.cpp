// Link: https://leetcode.com/problems/next-greater-element-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> s1, s2;
        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.back()] < nums[i]) {
                ans[s2.back()] = nums[i];
                s2.pop_back();
            }
            vector<int> temp;
            while (!s1.empty() && nums[s1.back()] < nums[i]) {
                temp.push_back(s1.back());
                s1.pop_back();
            }
            while (!temp.empty()) {
                s2.push_back(temp.back());
                temp.pop_back();
            }
            s1.push_back(i);
        }
        return ans;
    }
};
