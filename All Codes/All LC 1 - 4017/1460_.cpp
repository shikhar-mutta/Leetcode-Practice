// Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    //   approach 1: using hash map
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> freq; // frequency map
        for (int x : target)
            freq[x]++; // count frequency of each element in target
        for (int x : arr)
        {
            if (--freq[x] < 0) // if frequency becomes negative, it means arr has more occurrences of x than target
                return false;
        }
        return true;
    }

    // // approach 2: using sorting
    // bool canBeEqual(vector<int> &target, vector<int> &arr)
    // {
    //     sort(arr.begin(), arr.end());
    //     sort(target.begin(), target.end());
    //     int n = arr.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] != target[i]) // if any element is different, return false
    //             return false;
    //     }
    //     return true;
    // }
};
