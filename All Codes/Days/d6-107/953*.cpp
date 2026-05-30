// Link: https://leetcode.com/problems/verifying-an-alien-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> charOrder;
        for (int i = 0; i < order.size(); i++)
        {
            charOrder[order[i]] = i;
        }

        for (int i = 1; i < words.size(); i++)
        {
            const string &word1 = words[i - 1];
            const string &word2 = words[i];
            int minLength = min(word1.size(), word2.size());
            bool isSorted = false;

            for (int j = 0; j < minLength; j++)
            {
                if (charOrder[word1[j]] < charOrder[word2[j]])
                {
                    isSorted = true;
                    break;
                }
                else if (charOrder[word1[j]] > charOrder[word2[j]])
                {
                    return false;
                }
            }

            if (!isSorted && word1.size() > word2.size())
            {
                return false;
            }
        }

        return true;
    }
};
