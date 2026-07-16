// Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) + O(n) = O(n)
// SC: O(n) + O(n) = O(n)
//  Approach:
//   1. Create a frequency array to count the occurrences of each number in the input array A, but limit the count to n (the size of A) since any number greater than n can be treated as n for the purpose of this problem.
//   2. Iterate through the frequency array from 2 to n, and for each number i, update the result res to be the minimum of res + freq[i] and i. This ensures that we can only have at most i occurrences of the number i in the final array, and we can use any excess occurrences to fill in the gaps for smaller numbers.
//   3. Finally, return the result res, which represents the maximum element that can be achieved after rearranging and decrementing the elements of A according to the problem's constraints.

class Solution
{
    static inline int freq[100005];

public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &A)
    {
        int n = A.size();
        for (auto &x : A)
            freq[min(x, n)]++;

        int res = 1;
        for (int i = 2; i <= n; i++)
            res = min(res + freq[i], i);

        for (int i = 0; i <= n; i++)
            freq[i] = 0;

        return res;
    }
};