// Link: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long rem = 0;
        for (char c : word) {
            rem = (rem * 10 + (c - '0')) % m;
            ans.push_back(rem == 0 ? 1 : 0);
        }
        return ans;
    }
};
