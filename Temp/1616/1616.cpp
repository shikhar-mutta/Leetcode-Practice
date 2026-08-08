// Link: https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPal(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool check(const string& a, const string& b) {
        int i = 0, j = (int)a.size() - 1;
        while (i < j && a[i] == b[j]) { i++; j--; }
        if (i >= j) return true;
        return isPal(a, i, j) || isPal(b, i, j);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};
