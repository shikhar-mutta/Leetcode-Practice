// Link: https://leetcode.com/problems/rearrange-spaces-between-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string reorderSpaces(string text)
    {
        int cntSpaces = 0, cntWords = 0;
        for (char c : text)
            if (c == ' ')
                cntSpaces++;
        stringstream ss(text);
        string word;
        while (ss >> word)
            cntWords++;
        if (cntWords == 0)
            return text;
        if (cntWords == 1)
            return word + string(cntSpaces, ' ');
        int spacesBetweenWords = cntSpaces / (cntWords - 1);
        int extraSpaces = cntSpaces % (cntWords - 1);
        string result;
        ss.clear();
        ss.str(text);
        while (ss >> word)
        {
            result += word;
            if (--cntWords > 0)
                result += string(spacesBetweenWords, ' ');
        }
        result += string(extraSpaces, ' ');
        return result;
    }
};
