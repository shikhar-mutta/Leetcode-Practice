// Link: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        for (auto& g : groups) {
            bool found = false;
            while (pos + (int)g.size() <= n) {
                bool match = true;
                for (int i = 0; i < (int)g.size(); i++) {
                    if (nums[pos + i] != g[i]) { match = false; break; }
                }
                if (match) { found = true; pos += g.size(); break; }
                pos++;
            }
            if (!found) return false;
        }
        return true;
    }
};
