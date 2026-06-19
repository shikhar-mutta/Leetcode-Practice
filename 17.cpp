// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(4^n), SC: O(n)
    void backTrack(vector<string> &res, string &digits, vector<string> &keypad, int ind, string &current)
    {
        if (ind == (int)digits.size())
        {
            res.push_back(current);
            return;
        }
        string &letters = keypad[digits[ind] - '0']; // letters for this digit
        for (char c : letters)
        {
            current.push_back(c);
            backTrack(res, digits, keypad, ind + 1, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {}; // no digits → no combinations
        vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string current;
        backTrack(res, digits, keypad, 0, current);
        return res;
    }
};
