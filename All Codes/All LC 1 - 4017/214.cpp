// Link: https://leetcode.com/problems/shortest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(N)
    //  Approach:
    //  1. We can use the KMP algorithm to find the longest palindromic prefix of the given string. We can create a new string by concatenating the original string, a special character (e.g. '#'), and the reverse of the original string. We can then compute the longest prefix suffix (LPS) array for this new string. The last value of the LPS array will give us the length of the longest palindromic prefix of the original string. We can then take the substring of the reverse of the original string from the beginning to the length of the longest palindromic prefix and append it to the original string to get the shortest palindrome.
    // 2. The LPS array is computed by iterating through the new string and keeping track of the length of the longest prefix which is also a suffix for each position in the string. If the current character matches the character at the current length of the longest prefix, we increment the length and set it in the LPS array. If it doesn't match, we update the length to the value of the LPS at the previous position until we find a match or reach the beginning of the string.
    vector<int> f(string &s)
    {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++)
        {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];
            if (s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + '#' + rev;
        vector<int> lps = f(temp); // longest palindromic prefix
        int lpp = lps[temp.size() - 1];
        string res = rev.substr(0, n - lpp);
        res += s;
        return res;
    }
};