// Link: https://leetcode.com/problems/remove-comments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(n)
    //  Approach:
    //  1. We iterate through each line of the source code.
    //  2. For each line, we iterate through each character and check if it is part of a comment or not.
    //  3. If it is not part of a comment, we add it to a buffer string.
    //  4. If we reach the end of the line and we are not in a block comment, we add the buffer string to the result vector.
    //  5. Finally, we return the result vector.
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> res;
        string buffer;
        bool inBlock = false;
        for (auto &line : source)
        {
            int i = 0, n = line.size();
            if (!inBlock)
                buffer = "";
            while (i < n)
            {
                if (inBlock)
                {
                    if (i + 1 < n && line[i] == '*' && line[i + 1] == '/')
                    {
                        inBlock = false;
                        i += 2;
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                {
                    if (i + 1 < n && line[i] == '/' && line[i + 1] == '/')
                    {
                        break;
                    }
                    else if (i + 1 < n && line[i] == '/' && line[i + 1] == '*')
                    {
                        inBlock = true;
                        i += 2;
                    }
                    else
                    {
                        buffer += line[i];
                        i++;
                    }
                }
            }
            if (!inBlock && !buffer.empty())
            {
                res.push_back(buffer);
            }
        }
        return res;
    }
};
