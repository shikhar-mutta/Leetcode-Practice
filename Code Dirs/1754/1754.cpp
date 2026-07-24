// Link: https://leetcode.com/problems/largest-merge-of-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n + m)
//  Approach:
//    1. We can use two pointers to iterate through both strings and compare the characters at the current indices.
//    2. If the character in word1 is greater than the character in word2, we can add the character from word1 to the merge string and increment the index for word1.
//    3. If the character in word2 is greater than the character in word1, we can add the character from word2 to the merge string and increment the index for word2.
//    4. If the characters are equal, we can use a helper function to determine which word to choose by comparing the remaining characters in both words.
//    5. We can continue this process until we have iterated through both strings and return the merge string as the result.
// Note: The helper function compares the remaining characters in both words and returns true if word1 should be chosen, and false if word2 should be chosen.
class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        int index1 = 0;
        int index2 = 0;
        string merge = "";
        while (index1 < word1.size() && index2 < word2.size())
        {
            if (word1[index1] > word2[index2])
            {
                merge.push_back(word1[index1++]);
            }
            else if (word2[index2] > word1[index1])
            {
                merge.push_back(word2[index2++]);
            }
            else
            {
                bool chooseWord1 =
                    findWordToChoose(word1, word2, index1, index2);
                if (chooseWord1)
                {
                    char current = word1[index1];
                    while (index1 < word1.size() && word1[index1] == current)
                    {
                        merge.push_back(word1[index1++]);
                    }
                }
                else
                {
                    char current = word2[index2];
                    while (index2 < word2.size() && word2[index2] == current)
                    {
                        merge.push_back(word2[index2++]);
                    }
                }
            }
        }
        while (index1 < word1.size())
        {
            merge.push_back(word1[index1++]);
        }
        while (index2 < word2.size())
        {
            merge.push_back(word2[index2++]);
        }
        return merge;
    }

private:
    int findWordToChoose(string &word1, string &word2, int index1, int index2)
    {
        while (index1 < word1.size() && index2 < word2.size() &&
               word1[index1] == word2[index2])
        {
            index1++;
            index2++;
        }
        if (index1 == word1.size())
        {
            return false;
        }
        if (index2 == word2.size())
        {
            return true;
        }
        return word1[index1] > word2[index2];
    }
};
