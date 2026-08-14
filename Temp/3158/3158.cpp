// Link: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> seen;
        int res = 0;
        for (int x : nums) {
            if (seen.count(x)) res ^= x;
            else seen.insert(x);
        }
        return res;
    }
};
