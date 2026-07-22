// Link: https://leetcode.com/problems/longest-absolute-file-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input string. We are iterating through the input string once to calculate the length of the longest absolute file path.
    // SC: O(n) as we are using a vector to store the length of the path at each depth level. The size of the vector is equal to the maximum depth of the file system, which can be at most n in the worst case.
    //   Approach:
    //   1. We can use a vector to store the length of the path at each depth level. The index of the vector represents the depth level, and the value at that index represents the length of the path at that depth level.
    //   2. We can iterate through the input string line by line, where each line represents a file or directory. We can determine the depth level of each line by counting the number of leading tab characters ('\t').
    //   3. If the line represents a file (i.e., it contains a '.' character), we can update the maximum length of the absolute file path by adding the length of the file name to the length of the path at the current depth level. If the line represents a directory, we can update the length of the path at the next depth level by adding the length of the directory name plus one (for the '/' character) to the length of the path at the current depth level.
    //   4. We can continue this process until we have processed all lines in the input string, and return the maximum length of the absolute file path as the result.
    int lengthLongestPath(string input)
    {
        vector<int> pathLen(input.size() + 2, 0);
        int maxLen = 0;
        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n'))
        {
            int depth = 0;
            while (depth < (int)line.size() && line[depth] == '\t')
                depth++;
            string name = line.substr(depth);
            if (name.find('.') != string::npos)
                maxLen = max(maxLen, pathLen[depth] + (int)name.size());
            else
                pathLen[depth + 1] = pathLen[depth] + (int)name.size() + 1;
        }
        return maxLen;
    }
};
