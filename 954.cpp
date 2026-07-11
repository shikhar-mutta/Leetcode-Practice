// Link: https://leetcode.com/problems/array-of-doubled-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) for sorting the keys
// SC: O(n) for storing the frequency of each element
// Approach:
// 1. Count the frequency of each element in the array using an unordered_map.
// 2. Store the unique elements (keys) in a vector and sort them based on their absolute values.
// 3. Iterate through the sorted keys and check if the frequency of each element is less than or equal to the frequency of its double. If not, return false.
// 4. If all elements can be paired with their doubles, return true.
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> freq;

        for (int x : arr)
        {
            freq[x]++;
        }

        vector<int> keys;
        for (auto &p : freq)
        {
            keys.push_back(p.first);
        }

        sort(keys.begin(), keys.end(),
             [](int a, int b)
             {
                 return abs(a) < abs(b);
             });

        for (int x : keys)
        {
            if (freq[x] > freq[2 * x])
            {
                return false;
            }

            freq[2 * x] -= freq[x];
        }

        return true;
    }
};