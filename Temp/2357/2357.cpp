// Link: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> distinctNonZero;
        for (int x : nums) if (x != 0) distinctNonZero.insert(x);
        return distinctNonZero.size();
    }
};
