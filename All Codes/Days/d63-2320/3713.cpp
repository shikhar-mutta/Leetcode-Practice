// Link: https://leetcode.com/problems/longest-balanced-substring-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * 26) SC: O(1)
// Approach: n is small, so try every starting index and extend the
// substring right, maintaining per-letter counts. At each extension,
// check whether every present letter has the same count (all distinct
// nonzero frequencies equal); track the longest such length.
class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();

        // Transform char -> int
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - 'a';

        int result = 0;
        for (int l = 0; l < n; ++l)
        {
            // Early exit, can't be bigger
            if (n - l <= result)
                break;

            int cnt[26] = {0}; // Counts of every char
            int uniq = 0,
                maxfreq = 0; // Number of uniq chars and maximum frequency
            for (int r = l; r < n; ++r)
            {
                int i = a[r];

                // There was no this char before => one more uniq
                if (cnt[i] == 0)
                    ++uniq;

                ++cnt[i];
                // Update max frequency
                if (cnt[i] > maxfreq)
                    maxfreq = cnt[i];

                // Check if all uniq chars have maxfreq frequency then update
                // the result
                int cur = r - l + 1;
                if (uniq * maxfreq == cur && cur > result)
                    result = cur;
            }
        }
        return result;
    }
};