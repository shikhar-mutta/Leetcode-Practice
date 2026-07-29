// Link: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: We can use a vector of vectors to store the indices of each digit in the string s. We can also use a vector to keep track of the current position of each digit in the string s. We can iterate through each character in the string t and check if the current position of the digit in the string s is less than the current position of any smaller digit. If it is, we return false. Otherwise, we increment the current position of the digit in the string s. If we reach the end of the string t without returning false, we return true.
class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        vector<vector<int>> idx(10);
        vector<int> pos(10);

        for (int i = 0; i < s.size(); ++i)
            idx[s[i] - '0'].push_back(i);
        for (auto c : t)
        {
            int d = c - '0';
            if (pos[d] >= idx[d].size())
                return false;
            for (auto i = 0; i < d; ++i)
            {
                if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]])
                    return false;
            }
            ++pos[d];
        }

        return true;
    }
};