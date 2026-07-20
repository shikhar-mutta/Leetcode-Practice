// Link: https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n)
    // SC: O(n)
    //  Approach:
    //  1. Find the maximum element in the array and create a sieve of Eratosthenes up to max_element + 300 to find all prime numbers.
    //  2. Iterate through the array and for each element, if its index is even, find the next prime number greater than or equal to the element, and if its index is odd, find the next non-prime number greater than or equal to the element.
    //  3. Calculate the total number of operations required to transform the array into an alternating prime array by summing the differences between the original elements and the transformed elements.
    //  4. Return the total number of operations.
    int minOperations(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int N = mx + 300;
        vector<bool> isP(N + 1, true);
        isP[0] = isP[1] = false;
        for (int i = 2; i * i <= N; i++)
            if (isP[i])
                for (int j = i * i; j <= N; j += i)
                    isP[j] = false;
        int ops = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int u = nums[i];
            if (i % 2 == 0)
                while (!isP[u])
                    u++;
            else
                while (isP[u])
                    u++;
            ops += u - nums[i];
        }
        return ops;
    }
};
