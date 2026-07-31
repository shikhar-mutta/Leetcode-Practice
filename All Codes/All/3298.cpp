// Link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of word1
// SC: O(1) since we are using a fixed size array of 30 to store the frequency of characters in word2
// Approach: We can use a sliding window approach to find the number of substrings in word1 that can be rearranged to contain word2. We maintain a frequency array for the characters in word2 and a count of how many characters are still missing from the current window in word1. As we expand the window by moving the right pointer, we decrement the count of missing characters when we encounter a character from word2. When all characters are present (missing == 0), we can count all valid substrings ending at the current right pointer and starting from any position between left and right. We then move the left pointer to shrink the window and continue this process until we have processed the entire string.
class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        int dict[30] = {0};
        int left = 0;
        int len = word1.length(), missing = word2.length();
        long long answer = 0;
        for (auto ch : word2)
        {
            dict[ch - 'a']++;
        }
        for (int right = 0; right < len; right++)
        {
            int temp = word1[right] - 'a';
            if (dict[temp]-- > 0)
            {
                missing--;
            }
            while (missing == 0)
            {
                answer += len - right;
                temp = word1[left++] - 'a';
                if (++dict[temp] > 0)
                {
                    missing++;
                }
            }
        }
        return answer;
    }
};
