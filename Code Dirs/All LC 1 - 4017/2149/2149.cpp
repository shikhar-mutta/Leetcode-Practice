// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int pi = 0, ni = 1;
        for (int x : nums) {
            if (x > 0) { res[pi] = x; pi += 2; }
            else { res[ni] = x; ni += 2; }
        }
        return res;
    }
};
