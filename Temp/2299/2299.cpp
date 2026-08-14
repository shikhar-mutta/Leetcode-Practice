// Link: https://leetcode.com/problems/strong-password-checker-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        string special = "!@#$%^&*()-+";
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (int i = 0; i < (int)password.size(); i++) {
            char c = password[i];
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
            else if (special.find(c) != string::npos) hasSpecial = true;
            if (i > 0 && password[i] == password[i-1]) return false;
        }
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};
