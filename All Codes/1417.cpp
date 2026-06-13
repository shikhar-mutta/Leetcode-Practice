// Link: https://leetcode.com/problems/reformat-the-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string reformat(string s)
    {
        string digits, letters;
        for (char c : s) // classify characters into digits and letters
            if (isdigit(c))
                digits += c;
            else
                letters += c;

        int n = digits.size(), m = letters.size();

        if (abs(n - m) > 1) // if diff is greater than 1, it's impossible to reformat
            return "";
        string ans;
        bool digitFirst = n >= m; // set flag
        int i = 0, j = 0;
        while (i < n || j < m)
            if (digitFirst)
            {
                ans += digits[i++];
                digitFirst = false;
            }
            else
            {
                ans += letters[j++];
                digitFirst = true;
            }
        return ans;
    }
};
