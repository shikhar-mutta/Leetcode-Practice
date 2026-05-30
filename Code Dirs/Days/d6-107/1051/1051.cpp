// Link: https://leetcode.com/problems/height-checker/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected = heights;         // Create a copy of the original heights
        sort(expected.begin(), expected.end()); // Sort the expected heights

        int count = 0, n = heights.size(); // Initialize a counter for mismatches
        for (size_t i = 0; i < n; ++i)
        {
            if (heights[i] != expected[i])
            {
                ++count; // Increment the counter if there's a mismatch
            }
        }
        return count; // Return the total count of mismatches
    }
};
