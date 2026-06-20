// Link: https://leetcode.com/problems/strong-password-checker-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool strongPasswordCheckerII(string password)
    {
        if (password.size() < 8)
            return false; // rule: length >= 8
        string special = "!@#$%^&*()-+";
        bool lo = false, up = false, dig = false, spec = false;
        for (int i = 0; i < (int)password.size(); i++)
        {
            char c = password[i];
            if (i && c == password[i - 1])
                return false; // no two adjacent equal chars
            if (islower(c))
                lo = true;
            else if (isupper(c))
                up = true;
            else if (isdigit(c))
                dig = true;
            else if (special.find(c) != string::npos)
                spec = true;
            if (lo && up && dig && spec)
                break; // all char types found, can stop scanning
        }
        return lo && up && dig && spec; // needs all four char types
    }
};
