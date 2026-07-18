// Link: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Hashing. TC: O(n), SC: O(n)
    int mostFrequent(vector<int> &nums, int key)
    {
        // to store the frequency of numbers following the key(target)
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == key)
                freq[nums[i + 1]]++; // inc target frequency
        }

        // max frequency of target
        int maxFreq = 0;
        // to store the most frequent target
        int mostFreqNum = -1;

        for (const auto &[num, count] : freq)
        {
            if (count > maxFreq)
            {
                maxFreq = count;
                mostFreqNum = num;
            }
        }

        return mostFreqNum;
    }
};
