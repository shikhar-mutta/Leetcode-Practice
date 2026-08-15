// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
class Solution
{
public:
    string trim(string s)
    {
        string ans = "";
        int n = s.size(), i = 0, j = n - 1;
        while (i < n && s[i] == ' ')
            i++;
        while (j >= 0 && s[j] == ' ')
            j--;
        bool preSpace = false;
        while (i <= j)
        {
            if (s[i] == ' ' && preSpace)
            {
                i++;
                continue;
            }
            preSpace = (s[i] == ' ');
            ans += s[i++];
        }

        return ans;
    }
    string reverseWords(string s)
    {
        s = trim(s);
        int n = s.size(), i = 0, j;
        reverse(s.begin(), s.end());
        while (n > i)
        {
            j = i;
            while (j < n && s[j] != ' ')
                j++;
            reverse(s.begin() + i, s.begin() + j);
            j++;
            i = j;
        }
        return s;
    }
};
