// Link: https://leetcode.com/problems/letter-case-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), SC: O(n)
    //  Approach:
    //  1. Use backtracking to generate all possible combinations of letter case permutations.
    //  2. For each character in the string, if it is a letter, we can either keep it as is or change its case.
    //  3. If it is a digit, we can only keep it as is.
    //  4. We continue this process until we reach the end of the string, at which point we add the current permutation to the result.
    //  5. Finally, we return the result vector containing all permutations.
    void backtrack(string &s, int i, vector<string> &res)
    {
        if (i == (int)s.size())
        {
            res.push_back(s);
            return;
        }
        if (isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            backtrack(s, i + 1, res);
            s[i] = toupper(s[i]);
            backtrack(s, i + 1, res);
        }
        else
        {
            backtrack(s, i + 1, res);
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        backtrack(s, 0, res);
        return res;
    }
};
