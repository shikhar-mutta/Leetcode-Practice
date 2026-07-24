// Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//   Approach:
//    1. We use a bitmask to represent the parity (even or odd) of the counts of the vowels 'a', 'e', 'i', 'o', and 'u'. Each vowel is assigned a unique bit position in the mask. For example, 'a' is represented by the least significant bit (1), 'e' by the second least significant bit (2), 'i' by the third least significant bit (4), 'o' by the fourth least significant bit (8), and 'u' by the fifth least significant bit (16). The mask is initialized to 0, indicating that all vowel counts are even (zero counts).
//    2. We maintain an array bits of size 32 (2^5) to store the first occurrence of each unique mask value. The array is initialized with -2, except for bits[0], which is set to -1 to handle the case where the entire substring from the beginning has even counts of vowels.
//    3. We iterate through the input string s, updating the mask based on the current character. If the character is a vowel, we toggle the corresponding bit in the mask using the XOR operation. This effectively updates the parity of the vowel count for that character.
//    4. After updating the mask, we check if this mask value has been seen before by looking it up in the bits array. If it has not been seen before (bits[mask] == -2), we store the current index i in bits[mask] to record the first occurrence of this mask value. If it has been seen before, we calculate the length of the substring from the first occurrence of this mask value to the current index i, which is given by i - bits[mask]. We update the answer ans with the maximum length found so far.
//    5. Finally, we return ans, which represents the length of the longest substring containing vowels in even counts.
class Solution
{
public:
    bool isVowel(char ch)
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }
    int findTheLongestSubstring(string s)
    {
        vector<int> bits(33, -2);
        bits[0] = -1;
        int mask = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                if (s[i] == 'a')
                {
                    mask ^= 1;
                }
                else if (s[i] == 'e')
                {
                    mask ^= 2;
                }
                else if (s[i] == 'i')
                {
                    mask ^= 4;
                }
                else if (s[i] == 'o')
                {
                    mask ^= 8;
                }
                else
                {
                    mask ^= 16;
                }
            }
            if (bits[mask] == -2)
            {
                bits[mask] = i;
            }
            else
            {
                ans = max(ans, i - bits[mask]);
            }
        }
        return ans;
    }
};