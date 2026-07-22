// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. Use a sliding window of size equal to the length of string p.
    //  2. Maintain a frequency count of characters in the current window and compare it with the frequency count of characters in string p.
    //  3. If the counts match, it means the current window is an anagram of p, and we store the starting index of the window.
    //  4. Return the list of starting indices of all anagrams found in string s.
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (m > n)
            return res;
        vector<int> need(26, 0), window(26, 0);
        for (char c : p)
            need[c - 'a']++;
        for (int i = 0; i < n; i++)
        {
            window[s[i] - 'a']++;
            if (i >= m)
                window[s[i - m] - 'a']--;
            if (i >= m - 1 && window == need)
                res.push_back(i - m + 1);
        }
        return res;
    }
};
