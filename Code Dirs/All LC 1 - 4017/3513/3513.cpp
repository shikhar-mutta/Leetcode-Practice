// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int k = 1;
        while (k <= n) k <<= 1;
        return k;
    }
};
