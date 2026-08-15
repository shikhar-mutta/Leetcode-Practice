// Link: https://leetcode.com/problems/maximum-xor-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int result = 0;
        for (int x : nums) result |= x;
        return result;
    }
};
