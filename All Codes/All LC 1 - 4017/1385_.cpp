// Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using none_of() function
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int cnt = 0;
        for (int x : arr1)
        {
            // count x if no element in arr2 is within distance d
            // none_of() | any_of() | all_of() any of them used to check condition
            if (none_of(arr2.begin(), arr2.end(), [&](int y)
                        { return abs(x - y) <= d; }))
                cnt++;
        }
        return cnt;
    }

    // Approach 2: Using nested loops with early stopping
    // int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    // {
    //     int cnt = 0;
    //     for (auto a1 : arr1)
    //     {
    //         bool res = true;
    //         for (auto a2 : arr2)
    //             if (abs(a1 - a2) <= d) // Early Stopping
    //             {
    //                 res = false;
    //                 break;
    //             }
    //         if (res)
    //             cnt++;
    //     }
    //     return cnt;
    // }
};
