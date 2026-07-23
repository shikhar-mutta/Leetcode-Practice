// Link: https://leetcode.com/problems/longest-turbulent-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    // Approach:
    // 1. We can use two variables to keep track of the length of the current turbulent subarray and the length of the longest turbulent subarray found so far.
    // 2. We can iterate through the array and compare each element with the previous element to determine if the current subarray is turbulent or not.
    // 3. If the current subarray is turbulent, we increment the length of the current turbulent subarray and update the length of the longest turbulent subarray found so far if necessary.
    // 4. If the current subarray is not turbulent, we reset the length of the current turbulent subarray to 1 and continue iterating through the array.
    // 5. Finally, we return the length of the longest turbulent subarray found.
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        int best = 1, up = 1, down = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                up = down + 1;
                down = 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                down = up + 1;
                up = 1;
            }
            else
            {
                up = 1;
                down = 1;
            }
            best = max(best, max(up, down));
        }
        return best;
    }
};
