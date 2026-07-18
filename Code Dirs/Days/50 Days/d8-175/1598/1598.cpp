// Link: https://leetcode.com/problems/crawler-log-folder/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int depth = 0;
        for (const string &log : logs)
        {
            if (log == "../") // go back to the parent folder
            {
                if (depth > 0) // we can't go back to the parent folder if we are already in the main folder
                {
                    depth--;
                }
            }
            else if (log != "./") // move to a child folder
            {
                depth++;
            }
        }
        return depth;
    }
};
