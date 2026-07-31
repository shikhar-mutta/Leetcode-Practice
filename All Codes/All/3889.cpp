// Link: https://leetcode.com/problems/mirror-frequency-distance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: count frequency of each of the 36 possible characters
//  (letters + digits), compute each present character's mirror, and sum
//  |freq(c)-freq(mirror(c))| once per unmarked pair.
//  The mirror of a character is defined as follows:
//  - For lowercase letters, the mirror of 'a' is 'z', 'b' is 'y', 'c' is 'x', and so on, up to 'm' which is the mirror of 'n'.
//  - For digits, the mirror of '0' is '9', '1' is '8', '2' is '7', and so on, up to '4' which is the mirror of '5'.
//  The total distance is the sum of the absolute differences between the frequencies of each character and its mirror character.   
class Solution
{
public:
    int mirrorFrequency(string s)
    {
        vector<int> freq(256, 0);
        for (char c : s)
        {
            freq[int(c)]++;
        }
        int total_distance = 0;
        for (int i = 0; i < 13; i++)
        {
            char c1 = 'a' + i;
            char c2 = 'z' - i;
            if (freq[c1] > 0 || freq[c2] > 0)
            {
                total_distance += abs(freq[c1] - freq[c2]);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            char d1 = '0' + i;
            char d2 = '9' - i;
            if (freq[d1] > 0 || freq[d2] > 0)
            {
                total_distance += abs(freq[d1] - freq[d2]);
            }
        }
        return total_distance;
    }
};