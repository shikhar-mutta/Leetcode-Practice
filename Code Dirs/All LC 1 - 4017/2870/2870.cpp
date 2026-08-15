// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        int ops = 0;
        for (auto& [k, c] : freq) {
            if (c == 1) return -1;
            ops += (c + 2) / 3;
        }
        return ops;
    }
};
