// Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        if (nums2.size() % 2 == 1)
            for (int x : nums1) result ^= x;
        if (nums1.size() % 2 == 1)
            for (int x : nums2) result ^= x;
        return result;
    }
};
