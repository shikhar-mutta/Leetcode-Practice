// Link: https://leetcode.com/problems/circular-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();
        // wrap-around: first word's first char must equal last word's last char
        if (sentence[0] != sentence[n - 1])
            return false;
        // at each space, char before must equal char after (word boundary check)
        for (int i = 1; i < n - 1; ++i)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        return true;
    }
};
