// Link: https://leetcode.com/problems/decode-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(output length)  SC: O(output length)
// Approach: stack of (count, prefix string); on '[' push current state, on
// ']' pop and repeat the built string count times, append to prefix
class Solution {
public:
    string decodeString(string s) {
        vector<pair<int,string>> stk;
        int num = 0;
        string cur;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stk.push_back({num, cur});
                num = 0;
                cur = "";
            } else if (c == ']') {
                auto [k, prefix] = stk.back(); stk.pop_back();
                string repeated;
                for (int i = 0; i < k; i++) repeated += cur;
                cur = prefix + repeated;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};
