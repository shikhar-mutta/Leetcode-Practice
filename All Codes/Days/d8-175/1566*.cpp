// Link: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {

        int n = arr.size();
        // Iterate through the array and check for the pattern of length m repeated k or more times
        for (int i = 0; i <= n - m * k; i++)
        {
            bool match = true;
            // Check if the pattern of length m is repeated k times starting from index i
            for (int j = 0; j < m * k; j++)
            {
                if (arr[i + j] != arr[i + j % m])
                {
                    match = false;
                    break;
                }
            }
            // If the pattern matches, return true
            if (match)
                return true;
        }
        // If no pattern is found, return false
        return false;
    }
};
