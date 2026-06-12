// Link: https://leetcode.com/problems/remove-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int removePalindromeSub(string s)
    {
        while (s.length() > 0)
        {
            string t = s;
            reverse(t.begin(), t.end());
            if (s == t)
                return 1;                                      // If the string is already a palindrome, we can remove it in one step
            s.erase(remove(s.begin(), s.end(), 'a'), s.end()); // Remove all 'a's
            s.erase(remove(s.begin(), s.end(), 'b'), s.end()); // Remove all 'b's
        }
        return 2; // If the string is not a palindrome,
        // we can remove all 'a's in one step and all 'b's in another step
    }
};
