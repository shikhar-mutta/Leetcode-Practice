// Link: https://leetcode.com/problems/unique-number-of-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq; // Map to store the frequency of each number

        for (int num : arr)
        {
            freq[num]++; // Increment the frequency of the current number
        }

        unordered_set<int> occurrences; // Set to store unique frequencies

        for (const auto &entry : freq)
        {
            if (occurrences.count(entry.second))
            {
                return false; // If the frequency is already in the set, return false
            }
            occurrences.insert(entry.second); // Insert the frequency into the set
        }

        return true; // All frequencies are unique, return true
    }
};
