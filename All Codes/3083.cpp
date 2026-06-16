// Link: https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // unordered_set
    bool isSubstringPresent(string s)
    {
        // collect every adjacent pair, then check if any pair's reverse also occurs
        unordered_set<string> pairs;
        for (int i = 0; i + 1 < (int)s.size(); ++i)
            pairs.insert(s.substr(i, 2));
        for (int i = 0; i + 1 < (int)s.size(); ++i)
        {
            string rev = {s[i + 1], s[i]}; // reversed adjacent pair
            if (pairs.count(rev))
                return true;
        }
        return false;
    }
};
