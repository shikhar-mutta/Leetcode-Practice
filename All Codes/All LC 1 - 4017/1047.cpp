// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string removeDuplicates(string s)
    {
        string ans;
        for (auto ch : s)
        {
            if (!ans.empty() && ans.back() == ch)
                ans.pop_back();
            else
                ans.push_back(ch);
        };
        return ans;
    };
};