// Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> stk;
        for (int x : nums) {
            long long cur = x;
            while (!stk.empty()) {
                long long g = gcd(stk.back(), cur);
                if (g == 1) break;
                cur = stk.back() / g * cur;
                stk.pop_back();
            }
            stk.push_back(cur);
        }
        return vector<int>(stk.begin(), stk.end());
    }
};
