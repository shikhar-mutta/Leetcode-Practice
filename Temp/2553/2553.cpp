// Link: https://leetcode.com/problems/separate-the-digits-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            string s = to_string(x);
            for (char c : s) ans.push_back(c - '0');
        }
        return ans;
    }
};
