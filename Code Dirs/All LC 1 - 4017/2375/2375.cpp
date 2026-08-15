// Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res;
        vector<int> stk;
        for (int i = 0; i <= n; i++) {
            stk.push_back(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!stk.empty()) {
                    res += ('0' + stk.back());
                    stk.pop_back();
                }
            }
        }
        return res;
    }
};
