// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, parity = 0;
        for (int x : nums) {
            int effective = x ^ parity;
            if (effective == 0) {
                ops++;
                parity ^= 1;
            }
        }
        return ops;
    }
};
