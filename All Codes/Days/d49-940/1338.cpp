// Link: https://leetcode.com/problems/reduce-array-size-to-the-half/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of elements in arr.
    // SC: O(n) for storing the frequency of each element in arr.
    // Approach:
    // 1. Count the frequency of each element in arr using an unordered_map.
    // 2. Store the frequencies in a vector and sort it in descending order.
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;
        vector<int> counts;
        for (auto &[val, c] : freq)
            counts.push_back(c);
        sort(counts.begin(), counts.end(), greater<int>());
        int removed = 0, picked = 0, half = arr.size() / 2;
        for (int c : counts)
        {
            removed += c;
            picked++;
            if (removed >= half)
                break;
        }
        return picked;
    }
};
