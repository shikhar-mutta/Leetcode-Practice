// Link: https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: monotonic increasing stack - pop larger digits while removals
// remain, then trim remaining removals from the end and strip leading zeros
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (char c : num) {
            while (!stk.empty() && k > 0 && stk.back() > c) {
                stk.pop_back();
                k--;
            }
            stk += c;
        }
        while (k-- > 0) stk.pop_back();

        int i = 0;
        while (i < (int)stk.size() - 1 && stk[i] == '0') i++;
        stk = stk.substr(i);
        return stk.empty() ? "0" : stk;
    }
};
