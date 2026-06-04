// Link: https://leetcode.com/problems/prime-in-diagonal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m * sqrt(maxElement)), SC: O(1)
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        // Lambda function to check if a number is prime
        auto isPrime = [](int num)
        {
            if (num < 2)
                return false;
            int n = sqrt(num);
            for (int i = 2; i <= n; i++)
                if (num % i == 0)
                    return false;
            return true;
        };

        int maxPrime = 0;

        for (int i = 0; i < min(n, m); i++)
        {
            // Check primary diagonal
            if (isPrime(nums[i][i]))
                maxPrime = max(maxPrime, nums[i][i]);
            // Check secondary diagonal
            if (isPrime(nums[i][m - 1 - i]))
                maxPrime = max(maxPrime, nums[i][m - 1 - i]);
        }

        return maxPrime;
    }
};