// Link: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int maxWords = 0, temp;
        for (const string &sentence : sentences)
        {
            // count the number of spaces and add 1 to get the number of words
            temp = count(sentence.begin(), sentence.end(), ' ') + 1;
            maxWords = max(maxWords, temp);
        }
        return maxWords;
    }
};
