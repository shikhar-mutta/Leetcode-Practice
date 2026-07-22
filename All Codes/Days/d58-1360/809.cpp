// Link: https://leetcode.com/problems/expressive-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), where n is the number of words and m is the average length of the word.
    // SC: O(1), as we are using a constant amount of extra space.
    // Approach:
    // 1. For each word in the input vector, we check if it can be stretched to match the target string s.
    // 2. We use two pointers, one for the target string s and one for the current word, to compare the characters.
    // 3. We count the number of consecutive characters in both the target string and the current word.
    // 4. If the count of consecutive characters in the target string is less than the count in the current word, or if the count in the target string is greater than the count in the current word but less than 3, we return false.
    // 5. If we reach the end of both strings and all conditions are satisfied, we return true.
    // 6. We keep a count of the number of words that can be stretched to match the target string and return that count at the end.
    bool isstrechy(string s, string word)
    {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < word.size())
        {
            if (s[i] != word[j])
            {
                return false;
            }
            int scount = 0;
            char ch = s[i];

            while (i < s.size() && s[i] == ch)
            {
                scount++;
                i++;
            }
            int wcount = 0;
            ch = word[j];
            while (j < word.size() && ch == word[j])
            {
                wcount++;
                j++;
            }
            if (scount < wcount)
            {
                return false;
            }
            else if (scount > wcount && scount < 3)
            {
                return false;
            }
        }
        return i == s.size() && j == word.size();
    }
    int expressiveWords(string s, vector<string> &words)
    {
        int count = 0;
        for (string word : words)
        {
            if (isstrechy(s, word))
            {
                count++;
            }
        }
        return count;
    }
};