// Link: https://leetcode.com/problems/count-largest-group/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //    1. We create a vector sums of size 37 (to account for the maximum possible digit sum of 36, which occurs for the number 999999) to count how many numbers have each possible digit sum.
    //    2. We iterate through all numbers from 1 to n, calculate their digit sum using the digsum function, and increment the corresponding index in the sums vector.
    //    3. After populating the sums vector, we find the maximum count of numbers that share the same digit sum (maxi) and count how many digit sums have this maximum count (count).
    //    4. The function returns the count of the largest groups, which is the number of digit sums that have the maximum count of numbers.
    //    5. The digsum function calculates the sum of the digits of a given number n by repeatedly extracting the last digit and adding it to a running total until n becomes zero.
    int countLargestGroup(int n)
    {
        vector<int> sums(37);
        for (int i = 1; i <= n; i++)
            sums[digsum(i)]++;

        int maxi = 0, count = 0;
        for (int i : sums)
            if (i > maxi)
                maxi = i, count = 1;
            else if (i == maxi)
                ++count;

        return count;
    }
    int digsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};