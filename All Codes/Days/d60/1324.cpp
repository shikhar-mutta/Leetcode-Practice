// Link: https://leetcode.com/problems/print-words-vertically/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    // Approach:
    //  1. Split the input string into words and store them in a vector.
    //  2. Find the length of the longest word in the vector.
    //  3. Iterate through the characters of each word and construct the vertical representation of the words.
    //  4. For each character position, create a new string by taking the character from each word at that position. If a word is shorter than the current position, add a space instead.
    //  5. Trim trailing spaces from each constructed string and add it to the result vector.
    //  6. Return the result vector containing the vertical representation of the words.
    vector<string> printVertically(string s)
    {
        vector<string> a;
        string s1;
        int len = 0;
        for (char i : s)
        {
            if (isalpha(i))
            {
                s1 += i;
            }
            else
            {
                a.push_back(s1);
                if (s1.size() > len)
                {
                    len = s1.size();
                }
                s1 = "";
            }
        }
        if (s1.size() > len)
        {
            len = s1.size();
        }
        a.push_back(s1);
        int i = 0;
        vector<string> r;
        while (i < len)
        {
            string res;
            int l = 0;
            int x = 0;
            for (int j = 0; j < a.size(); j++)
            {
                if (i >= a[j].size() || !isalpha(a[j][i]))
                {
                    res += ' ';
                }
                else
                {
                    x = j;
                    res += a[j][i];
                }
            }
            size_t last = res.find_last_not_of(" ");
            if (last != string::npos)
            {
                res.erase(last + 1);
            }
            else
            {
                res.clear();
            }
            r.push_back(res);
            i++;
        }
        return r;
    }
};