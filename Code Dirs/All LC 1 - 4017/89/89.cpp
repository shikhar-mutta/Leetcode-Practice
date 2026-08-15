// Link: https://leetcode.com/problems/gray-code/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n)  SC: O(1) extra (excluding output)
// Approach: standard binary-to-Gray formula, i ^ (i >> 1), for i = 0..2^n-1
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < (1 << n); i++) res.push_back(i ^ (i >> 1));
        return res;
    }
};
