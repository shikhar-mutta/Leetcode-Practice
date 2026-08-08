// Link: https://leetcode.com/problems/arithmetic-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArith(vector<int> v) {
        sort(v.begin(), v.end());
        if (v.size() < 2) return true;
        int diff = v[1] - v[0];
        for (int i = 2; i < (int)v.size(); i++) {
            if (v[i] - v[i - 1] != diff) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < (int)l.size(); i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(isArith(sub));
        }
        return ans;
    }
};
