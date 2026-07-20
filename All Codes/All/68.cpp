// Link: https://leetcode.com/problems/text-justification/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of words in the input vector
    // SC: O(n) for the output vector of strings
    // Approach:
    //   1. Initialize an empty vector of strings to store the justified lines.
    //   2. Iterate through the input vector of words and group them into lines based on the maximum width.
    //   3. For each line, calculate the number of spaces needed to justify the text and distribute them evenly between the words.
    //   4. If the line has only one word or is the last line, left-justify it by adding spaces to the end of the line.
    //   5. Add the justified line to the output vector and continue to the next line until all words are processed.
    //   6. Return the output vector of justified lines.
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int n = words.size();
        int i = 0;
        while (i < n)
        {
            int j = i, lineLen = 0;
            while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth)
                lineLen += words[j++].size();
            int numWords = j - i;
            int totalSpace = maxWidth - lineLen;
            string line;
            if (numWords == 1 || j == n)
            {
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                line += string(maxWidth - (int)line.size(), ' ');
            }
            else
            {
                int gaps = numWords - 1;
                int baseSpace = totalSpace / gaps;
                int extra = totalSpace % gaps;
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k != j - 1)
                    {
                        int spaces = baseSpace + (k - i < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};
