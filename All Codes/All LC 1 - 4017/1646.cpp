// Link: https://leetcode.com/problems/get-maximum-in-generated-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        int mx = n >= 1 ? 1 : 0;
        vector<int> arr(n + 1, 0);
        arr[0] = 0;
        if (n >= 1)
            arr[1] = 1;
        // Generate the array based on the given rules
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0) // If i is even, arr[i] = arr[i / 2]
            {
                arr[i] = arr[i / 2];
            }
            else // If i is odd, arr[i] = arr[i / 2] + arr[i / 2 + 1]
            {
                arr[i] = arr[i / 2] + arr[i / 2 + 1];
            }
            if (arr[i] > mx) // Update the maximum value found so far
                mx = arr[i];
        }
        return mx;
    }
};
