// Link: https://leetcode.com/problems/check-distances-between-same-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: use Unordered Map. TC: O(n), SC: O(1).
    bool checkDistances(string s, vector<int> &distance)
    {
        unordered_map<char, int> lastIndex; // to store the last index of each character
        int n = s.size();
        // iterate through the string and check the distance for each character
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (lastIndex.count(c))
                if (distance[c - 'a'] != i - lastIndex[c] - 1) // if they don't match, return false
                    return false;
            lastIndex[c] = i; // update the last index of this character
        }
        return true; // if we passed through all characters without mismatch, return true
    }
};
