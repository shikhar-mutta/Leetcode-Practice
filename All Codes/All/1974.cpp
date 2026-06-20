// Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minTimeToType(string word)
    {
        int total = 0;
        char prev = 'a'; // pointer starts at 'a'
        for (char c : word)
        {
            int d = abs(c - prev);
            total += min(d, 26 - d) + 1; // shorter rotation (either direction) + 1 to type
            prev = c;
        }
        return total;
    }
};
