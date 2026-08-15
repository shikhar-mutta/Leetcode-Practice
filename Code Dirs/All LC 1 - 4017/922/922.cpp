// Link: https://leetcode.com/problems/sort-array-by-parity-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int evenIdx = 0, oddIdx = 1;
        for (int x : nums) {
            if (x % 2 == 0) { res[evenIdx] = x; evenIdx += 2; }
            else { res[oddIdx] = x; oddIdx += 2; }
        }
        return res;
    }
};
