// Link: https://leetcode.com/problems/special-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the length of the string
    // SC: O(n)
    // Approach:
    //   1. Split the string into special binary substrings.
    //   2. Recursively sort the substrings in descending order.
    //   3. Concatenate the sorted substrings to form the largest special binary string
    //   4. Return the result.
    string makeLargestSpecial(string s)
    {
        vector<string> parts;
        int bal = 0, start = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            bal += s[i] == '1' ? 1 : -1;
            if (bal == 0)
            {
                parts.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }
        sort(parts.rbegin(), parts.rend());

        string res;
        for (auto &p : parts)
            res += p;
        return res;
    }
};
