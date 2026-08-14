// Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (int v : derived) x ^= v;
        return x == 0;
    }
};
