// Link: https://leetcode.com/problems/determine-if-two-strings-are-close/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the length of the string
// SC: O(1) as we are using a constant space
// Approach:
//   1. We can use two frequency arrays to store the frequency of each character in both strings.
//   2. We can then check if the two frequency arrays are equal or not  
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> f1(26, 0), f2(26, 0);
        for (char c : word1)
            f1[c - 'a']++;
        for (char c : word2)
            f2[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if ((f1[i] == 0) != (f2[i] == 0))
                return false; // must use the same set of letters
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2; // frequency multisets must match
    }
};
