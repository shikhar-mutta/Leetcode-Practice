// Link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)
// SC: O(1)
// Approach:
//  1. If the size of the array is less than or equal to 4, we can change all the elements to be equal, so the minimum difference is 0.
//  2. If the size of the array is greater than 4, we can sort the array and consider the four largest and four smallest elements. We can change at most three of these elements to minimize the difference between the largest and smallest values. The minimum difference can be calculated by considering the following cases:
//     - Change the three largest elements to be equal to the fourth largest element.
class Solution
{
public:
    int minDifference(vector<int> &A)
    {
        int n = A.size();
        if (n < 5)
            return 0;
        partial_sort(A.begin(), A.begin() + 4, A.end());
        nth_element(A.begin() + 4, A.end() - 4, A.end());
        sort(A.end() - 4, A.end());
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
    }
};