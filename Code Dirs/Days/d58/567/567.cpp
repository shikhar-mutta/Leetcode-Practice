// Link: https://leetcode.com/problems/permutation-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //   Approach:
    //   1. We use a sliding window approach to check if any substring of s2 is a permutation of s1. We maintain two frequency arrays, freq1 and freq2, where freq1 stores the frequency of characters in s1 and freq2 stores the frequency of characters in the current window of s2.
    //   2. We initialize the frequency arrays by counting the characters in s1 and the first window of s2. We then slide the window across s2, updating the frequency array for the current window and checking if it matches freq1. If we find a match, we return true. If we reach the end of s2 without finding a match, we return false.
    //   3. The frequency arrays are of fixed size (26 for lowercase English letters), so the space complexity is O(1). The time complexity is O(n), where n is the length of s2, since we process each character in s2 at most twice (once when it enters the window and once when it leaves).
    //   4. This approach is efficient and works well for the given problem constraints.
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < s1.length(); i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int windsize = s1.length();
        for (int i = 0; i < s2.length() - windsize; i++)
        {
            if (freq1 == freq2)
                return true;
            freq2[s2[i] - 'a']--;
            freq2[s2[i + windsize] - 'a']++;
        }
        return freq1 == freq2;
    }
};