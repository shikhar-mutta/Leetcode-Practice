// Link: https://leetcode.com/problems/capitalize-the-title/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        string res;
        stringstream ss(title);
        string word;
        while (ss >> word)
        {
            if (word.size() <= 2)
            {
                // lowercase
                for (char &c : word)
                    c = tolower(c);
            }
            else
            {
                // capitalize first letter, lowercase the rest
                word[0] = toupper(word[0]);
                for (int i = 1; i < (int)word.size(); i++)
                    word[i] = tolower(word[i]);
            }
            if (!res.empty())
                res += ' ';
            res += word;
        }
        return res;
    }
};
