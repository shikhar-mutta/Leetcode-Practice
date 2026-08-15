// Link: https://leetcode.com/problems/valid-binary-strings-with-cost-limit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n). SC: O(n).
    // Backtracking helper function to generate valid binary strings
    void helper(vector<string> &ans, string &curr, int i, int n, int k)
    {
        if (k < 0) // cost limit exceeded
            return;

        if (i == n) // reached the end of the string
        {
            ans.emplace_back(curr);
            return;
        }

        curr.push_back('0'); // cost of adding '0' is 0, so we don't reduce k
        helper(ans, curr, i + 1, n, k);
        curr.pop_back();

        if (curr.empty() || curr.back() != '1')
        {
            curr.push_back('1'); // cost of adding '1' is i, so we reduce k by i
            helper(ans, curr, i + 1, n, k - i);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k)
    {
        vector<string> ans;
        string curr = "";
        helper(ans, curr, 0, n, k);
        return ans;
    }
};