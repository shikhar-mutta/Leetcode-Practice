// Link: https://leetcode.com/problems/maximum-palindromes-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + m), SC: O(1)
    //  Approach:
    //   1. Create an array alpha of size 26 to store the frequency of each character in the words.
    //   2. Initialize variables pairs and result to 0
    //   3. Iterate through each word in words:
    //      a. For each character in the word, increment its frequency in alpha and update pairs if the frequency is even.
    //      b. Store the length of the word in a vector size.
    //   4. Sort the size vector in ascending order.
    //   5. Iterate through each length in size:
    //      a. Decrement pairs by half of the length of the word.
    //      b. If pairs is still non-negative, increment result by 1.
    //   6. Return result as the maximum number of palindromes that can be formed after performing the operations.
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        int alpha[26] = {};
        int pairs = 0, result = 0;
        vector<int> size;
        for (auto &it : words)
        {
            for (auto &ch : it)
            {
                pairs += (++alpha[ch - 'a']) % 2 == 0;
            }
            size.push_back(it.length());
        }
        sort(size.begin(), size.end());
        for (auto &it : size)
        {
            pairs -= it / 2;
            if (pairs >= 0)
            {
                result += 1;
            }
        }
        return result;
    }
};