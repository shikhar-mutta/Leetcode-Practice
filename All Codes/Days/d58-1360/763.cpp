// Link: https://leetcode.com/problems/partition-labels/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. The function initializes a vector lastIdx of size 26 to store the last occurrence index of each character in the input string s.
    //  2. It iterates through the string s and updates the lastIdx vector with the index of the last occurrence of each character.
    //  3. The function then iterates through the string again, maintaining two pointers start and end to track the current partition's start and end indices.
    //  4. For each  character in the string, it updates the end pointer to the maximum of its current value and the last occurrence index of that character.
    vector<int> partitionLabels(string s)
    {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < (int)s.size(); i++)
            lastIdx[s[i] - 'a'] = i;

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            end = max(end, lastIdx[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
