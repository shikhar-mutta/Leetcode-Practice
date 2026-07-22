// Link: https://leetcode.com/problems/reconstruct-original-digits-from-english/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string
    // SC: O(1) as we are using a fixed size array to store the count of each character
    // Approach:
    //  1. We will count the frequency of each character in the input string.
    //  2. We will use the unique characters in the words "zero", "two", "four", "six", "eight" to identify the digits 0, 2, 4, 6, 8 respectively.
    //  3. We will then use the characters 'h', 'f', 's', 'i', 'o' to identify the digits 3, 5, 7, 9, 1 respectively after accounting for the previously identified digits.
    //  4. Finally, we will construct the output string by appending the digits in ascending order based on their counts.
    string originalDigits(string s)
    {
        int cnt[26] = {0};
        for (char c : s)
            cnt[c - 'a']++;

        int digits[10] = {0};
        digits[0] = cnt['z' - 'a'];
        digits[2] = cnt['w' - 'a'];
        digits[4] = cnt['u' - 'a'];
        digits[6] = cnt['x' - 'a'];
        digits[8] = cnt['g' - 'a'];
        digits[3] = cnt['h' - 'a'] - digits[8];
        digits[5] = cnt['f' - 'a'] - digits[4];
        digits[7] = cnt['s' - 'a'] - digits[6];
        digits[9] = cnt['i' - 'a'] - digits[5] - digits[6] - digits[8];
        digits[1] = cnt['o' - 'a'] - digits[0] - digits[2] - digits[4];

        string result;
        for (int d = 0; d <= 9; d++)
            result += string(digits[d], '0' + d);
        return result;
    }
};
