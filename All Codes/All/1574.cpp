// Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach:
    //  1. We will create two vectors, one for the left sorted subarray and one for the right sorted subarray.
    //  2. We will iterate through the array and add elements to the left sorted subarray until we find an element that is smaller than the previous element.
    //  3. We will then iterate through the array from the end and add elements to the right sorted subarray until we find an element that is smaller than the next element.
    //  4. We will then iterate through the left sorted subarray and for each element, we will find the first element in the right sorted subarray that is greater than or equal to the current element
    //  5. We will then calculate the length of the subarray that needs to be removed and keep track of the maximum length of the sorted subarray that can be formed by removing the elements in between the left and right sorted subarrays.
    //  6. Finally, we will return the length of the original array minus the maximum length of the sorted subarray that can be formed by removing the elements in between the left and right sorted subarrays.
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n, m, i, j, k, x, y, z, p, q, l, r, r1, r2;
        vector<int> vec, vec2;
        n = arr.size();
        int flag = 1;
        for (i = 1; i < n; i++)
            if (arr[i] < arr[i - 1])
                flag = 0;
        if (flag)
            return 0;
        vec.push_back(arr[0]);
        for (i = 1; i < n; i++)
        {
            if (arr[i] >= arr[i - 1])
            {
                vec.push_back(arr[i]);
            }
            else
                break;
        }
        r1 = vec.size() - 1;
        vec2.push_back(arr[n - 1]);
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] >= arr[i])
            {
                vec2.push_back(arr[i]);
            }
            else
                break;
        }
        reverse(vec2.begin(), vec2.end());
        r2 = vec2.size() - 1;
        int mx = max(r1, r2) + 1;

        for (; r1 >= 0; r1--)
        {
            while (r2 >= 0 && vec2[r2] >= vec[r1])
                r2--;
            x = r1 + 1 + vec2.size() - 1 - r2;
            mx = max(mx, x);
        }
        return n - mx;
    }
};
