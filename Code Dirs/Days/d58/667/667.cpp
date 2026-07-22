// Link: https://leetcode.com/problems/beautiful-arrangement-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the array, as we iterate through the array once to fill it with the required values.
    // SC: O(n) where n is the size of the array, as we use an additional array to store the result.
    //    Approach:
    //    1. We initialize two pointers, left and right, to the start and end of the array, respectively.
    //    2. We fill the first (n-k) elements of the array with consecutive integers starting from 1 to (n-k).
    //    3. We then fill the remaining k elements of the array by alternating between the left and right pointers, starting with the left pointer. This creates the required k distinct differences in the array.
    //    4. Finally, we return the constructed array.
    vector<int> constructArray(int n, int k)
    {
        vector<int> res(n);

        int left = 1, right = n;

        // 1,2,3...
        for (int i = 0; i < (n - k); i++)
        {
            res[i] = left++;
        }

        // maximum element at (n-k)th index
        res[n - k] = right--;

        bool add_left = true;

        // for index b/w [n-k+1,n) -> alternate b/w min and max
        for (int i = n - k + 1; i < n; i++)
        {
            res[i] = (add_left) ? left++ : right--;
            add_left = !add_left;
        }

        return res;
    }
};