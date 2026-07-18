// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(26) ~ O(nlogn).SC: O(26) ~ O(1)
    // Approach:
    // 1. Count the frequency of each character in the word.
    // 2. Sort the frequencies in descending order.
    // 3. For each character, calculate the number of pushes required based on its position
    //    in the sorted frequency list. The first 8 characters require 1 push,
    //    the next 8 characters require 2 pushes, and so on.
    // 4. Sum the total number of pushes required for all characters and return the result.
    // 5. Return the total number of pushes required to type the word.
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (auto c : word)
        {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++)
        {
            int pushCnt = (i / 8) + 1;
            ans += (freq[i] * pushCnt);
        }
        return ans;
    }
};