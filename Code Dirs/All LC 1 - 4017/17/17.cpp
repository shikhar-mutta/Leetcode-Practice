// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^n * n)  SC: O(n) recursion depth (excluding output)
// Approach: backtracking, at each digit try every mapped letter, building the combination string
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string cur;
        function<void(int)> bt = [&](int idx) {
            if (idx == (int)digits.size()) { res.push_back(cur); return; }
            for (char c : map[digits[idx] - '0']) {
                cur += c;
                bt(idx + 1);
                cur.pop_back();
            }
        };
        bt(0);
        return res;
    }
};
