// Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string cur;
        function<void()> rec = [&]() {
            if ((int)cur.size() == n) { res.push_back(cur); return; }
            cur += '1';
            rec();
            cur.pop_back();
            if (cur.empty() || cur.back() != '0') {
                cur += '0';
                rec();
                cur.pop_back();
            }
        };
        rec();
        sort(res.begin(), res.end());
        return res;
    }
};
