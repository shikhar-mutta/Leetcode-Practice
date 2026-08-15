// Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> distinctGreater;
        for (int x : nums) {
            if (x < k) return -1;
            if (x > k) distinctGreater.insert(x);
        }
        return distinctGreater.size();
    }
};
