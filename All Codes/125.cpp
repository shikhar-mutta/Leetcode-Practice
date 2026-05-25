// Link : https://leetcode.com/problems/valid-palindrome/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach1: store only alphanumeric characters in a string and then check if the string is palindrome or not

    bool isAlNum(char c)
    {
        // check if the character is alphanumeric or not
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    string makeStr(string s)
    {
        // make a string which contains only alphanumeric characters and convert all characters to lowercase
        string temp = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isAlNum(s[i]))
            {
                temp += s[i];
            }
        }
        // convert all characters to lowercase ****
        for (auto &x : temp)
        {
            x = tolower(x);
        }
        return temp;
    }
    bool isPalindrome(string s)
    {
        string tmp = makeStr(s);
        string rev = tmp;
        reverse(rev.begin(), rev.end());
        // check if the string is palindrome or not
        if (rev == tmp)
            return true;
        else
            return false;
    }
};