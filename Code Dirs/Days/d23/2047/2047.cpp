// Link: https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countValidWords(string sentence)
    {
        auto valid = [](const string &w)
        {
            int n = w.size(), hyphens = 0, puncts = 0;
            for (int i = 0; i < n; i++)
            {
                char c = w[i];
                if (isdigit((unsigned char)c))
                    return false; // no digits allowed
                if (c == '-')
                {
                    // at most one hyphen, and it must sit between two letters
                    if (++hyphens > 1)
                        return false;
                    if (i == 0 || i == n - 1 ||
                        !islower(w[i - 1]) || !islower(w[i + 1]))
                        return false;
                }
                else if (c == '!' || c == '.' || c == ',')
                {
                    // at most one punctuation, only as the last char
                    if (++puncts > 1 || i != n - 1)
                        return false;
                }
                else if (!islower((unsigned char)c))
                {
                    return false; // only lowercase letters otherwise
                }
            }
            return true;
        };

        int cnt = 0;
        string w;
        stringstream ss(sentence);
        while (ss >> w)
            if (valid(w))
                cnt++; // >> skips runs of spaces
        return cnt;
    }
};
