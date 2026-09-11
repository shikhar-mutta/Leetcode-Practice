// Link: https://leetcode.com/problems/duplicate-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size(), zeros = 0;
        for (int x : arr)
            if (x == 0)
                zeros++; // Count the number of zeros in the array

        // We will iterate the array from the end and duplicate the zeros in place
        for (int i = n - 1, j = n + zeros - 1; i >= 0; --i, --j)
        {
            // If the current element is zero, we need to duplicate it
            if (arr[i] == 0)
            {
                if (j < n) // If j is within the bounds of the array, set it to zero
                    arr[j] = 0;
                --j;
                if (j < n) // If j is within the bounds of the array, set it to zero
                    arr[j] = 0;
            }
            else
            {
                if (j < n) // If j is within the bounds of the array, set it to the current element
                    arr[j] = arr[i];
            }
        }
    }
};
