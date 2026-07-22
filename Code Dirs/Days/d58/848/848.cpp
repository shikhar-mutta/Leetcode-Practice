// Link: https://leetcode.com/problems/shifting-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the string s.
    // SC: O(1), as we are using constant space.
    //  Approach:
    //  1. We iterate through the string s from the end to the beginning.
    //  2. We keep track of the total number of shifts that need to be applied to each character in the string.
    //  3. We apply the total number of shifts to each character in the string and update the character accordingly.
    //  4. Finally, we return the updated string s.
    string shiftingLetters(string &s, vector<int> &shifts)
    {
        const size_t n = s.size();
        uint8_t total{};
        for (size_t i{n}; i-- > 0;)
        {
            total = (total + (shifts[i] % 26)) % 26;
            s[i] -= 'a';
            s[i] = (s[i] + total) % 26 + 'a';
        }

        return s;
    }
};