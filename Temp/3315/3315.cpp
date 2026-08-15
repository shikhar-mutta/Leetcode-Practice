// Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) {
            if (x == 2) { res.push_back(-1); continue; }
            int z = 0;
            while (x & (1LL << z)) z++;
            int p = z - 1;
            res.push_back(x & ~(1 << p));
        }
        return res;
    }
};
