// Link: https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach:
    // 1. We will check if we can form a palindrome by taking prefix from string a and suffix from string b.
    // 2. We will check if we can form a palindrome by taking prefix from string b and suffix from string a.
    // 3. If we can form a palindrome in either of the above two cases, we will return true. Otherwise, we will return false.
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool check(string &a, string &b)
    {
        int i = 0;
        int j = a.size() - 1;
        while (i < j && a[i] == b[j])
        {
            i++;
            j--;
        }

        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b)
    {
        return check(a, b) || check(b, a);
    }
};