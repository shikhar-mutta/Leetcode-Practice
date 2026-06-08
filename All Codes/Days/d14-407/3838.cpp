// Link: https://leetcode.com/problems/weighted-word-mapping/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m) where n is the number of words and m is the average length of the words
    // SC: O(n) for the result string
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {

        string result;
        for (auto &word : words)
        {
            int weight = 0;
            for (auto &ch : word)
            {
                weight += weights[ch - 'a'];
            }
            result += (char)('z' - weight % 26);
        }
        return result;
    }
};
