// Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 2:  sort by bit count and then by value using a custom comparator
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int a, int b) // sort by bit count and then by value
             {
            int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
            return ca != cb ? ca < cb : a < b; });
        return arr;
    }

    // // approach 1:  sort by bit count and then by value
    // vector<int> sortByBits(vector<int> &arr)
    // {
    //     map<int, vector<int>> bitCountMap; // bit count -> list of numbers with that bit count
    //     for (int num : arr)
    //     {
    //         int bitCount = __builtin_popcount(num); // count the number of 1 bits in the binary representation of num
    //         bitCountMap[bitCount].push_back(num);   // group numbers by their bit count
    //     }
    //     vector<int> ans;
    //     for (auto &it : bitCountMap)
    //     {
    //         sort(it.second.begin(), it.second.end()); // sort numbers with the same bit count
    //         for (auto vals : it.second)
    //             ans.push_back(vals);
    //     }
    //     return ans;
    // }
};
