// Link: https://leetcode.com/problems/separate-black-and-white-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0, ans = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else ans += ones;
        }
        return ans;
    }
};
