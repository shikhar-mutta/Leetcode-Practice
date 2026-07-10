// Link: https://leetcode.com/problems/groups-of-special-equivalent-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m log m) where n is the number of words and m is the length of the longest word
// SC: O(n * m) where n is the number of words and m is the length of the longest word
// Approach: For each word, we can separate the characters at even and odd indices, sort them, and concatenate them to form a unique representation of the word.
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &words)
    {
        unordered_set<string> st;
        for (string &w : words)
        {
            string even, odd;
            for (int i = 0; i < w.size(); i++)
            {
                if (i % 2 == 0)
                    even += w[i];
                else
                    odd += w[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + "#" + odd);
        }
        return st.size();
    }
};