// Link: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
//  Approach: We can iterate through the array and for each element, we can keep track of the minimum value of the mysterious function that can be obtained by taking the bitwise AND of the current element and all the previous elements. We can update the minimum value of the mysterious function and return the minimum absolute difference between the minimum value of the mysterious function and the target.
class Solution
{
public:
    int closestToTarget(vector<int> &arr, int target)
    {
        int ans = INT_MAX;

        for (int i = 0; i < arr.size(); i++)
        {
            ans = min(ans, abs(arr[i] - target));

            for (int j = i - 1; j >= 0 && arr[j] != (arr[j] & arr[i]); j--)
            {
                arr[j] &= arr[i];
                ans = min(ans, abs(arr[j] - target));
            }
        }

        return ans;
    }
};