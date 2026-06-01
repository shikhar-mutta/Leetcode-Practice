// Link: https://leetcode.com/problems/minimum-absolute-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // Approach 1: Sort the array and find the minimum absolute difference
    // vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    // {
    //     sort(arr.begin(), arr.end()); // Sort the array to ensure pairs are in ascending order
    //     vector<vector<int>> result;   // Vector to store the pairs with the minimum absolute difference
    //     int minDiff = INT_MAX;        // Initialize minDiff to the maximum possible integer value

    //     for (size_t i = 1; i < arr.size(); ++i)
    //     {
    //         int diff = arr[i] - arr[i - 1];
    //         if (diff < minDiff)
    //         {
    //             minDiff = diff; // Update minDiff to the new smaller difference
    //             result.clear(); // Clear the result vector as we found a smaller difference
    //             result.push_back({arr[i - 1], arr[i]});
    //         }
    //         else if (diff == minDiff)
    //         {
    //             result.push_back({arr[i - 1], arr[i]}); // Add MinDiff pair to the result vector
    //         }
    //     }

    //     return result;
    // }

    // Approach 2: Sort the array and find the minimum absolute difference in two passes
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end()); // Sort Array

        int minDiff = INT_MAX;

        for (int i = 1; i < (int)arr.size(); ++i) // Find Minimum Absolute Difference
            minDiff = min(minDiff, arr[i] - arr[i - 1]);

        vector<vector<int>> result; // Answer Vector

        for (int i = 1; i < (int)arr.size(); ++i)
            if (arr[i] - arr[i - 1] == minDiff)
                result.push_back({arr[i - 1], arr[i]});

        return result;
    }
};
