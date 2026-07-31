// Link: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stk;
        int ans = 0;
        for (int x : nums) {
            if (x == 0) {
                stk.clear();
                continue;
            }
            while (!stk.empty() && stk.back() > x) stk.pop_back();
            if (stk.empty() || stk.back() != x) {
                stk.push_back(x);
                ans++;
            }
        }
        return ans;
    }
};
