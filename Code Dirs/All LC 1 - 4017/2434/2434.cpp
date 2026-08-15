// Link: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suffixMin(n + 1, 'z' + 1);
        for (int i = n - 1; i >= 0; i--)
            suffixMin[i] = min(suffixMin[i+1], s[i]);

        string result;
        string stk;
        for (int i = 0; i < n; i++) {
            stk.push_back(s[i]);
            while (!stk.empty() && stk.back() <= suffixMin[i+1]) {
                result.push_back(stk.back());
                stk.pop_back();
            }
        }
        while (!stk.empty()) {
            result.push_back(stk.back());
            stk.pop_back();
        }
        return result;
    }
};
