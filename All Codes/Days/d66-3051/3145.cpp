// Link: https://leetcode.com/problems/find-products-of-elements-of-big-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: We can use a vector to store the products of elements of the big array.
//  We can then use a for loop to iterate through the queries and calculate the product of elements from the big array for each query. We can then return the result as a vector of integers.
//  However, this approach is not efficient for large inputs. Instead, we can use a mathematical approach to calculate the product of elements in the big array without explicitly storing them. The product of elements from index 'from' to 'to' can be represented as 2 raised to the power of the sum of the exponents of 2 in the binary representation of numbers from 'from' to 'to'. We can calculate this sum using a helper function and then compute the result using modular exponentiation.

class Solution
{
private:
    // Helper to count total set bits in numbers 1..N
    long long countBitsUpTo(long long N)
    {
        long long count = 0;
        for (int b = 0; (1LL << b) <= N; ++b)
        {
            long long period = 1LL << (b + 1);
            long long full = (N + 1) / period;
            long long rem = (N + 1) % period;
            count += full * (1LL << b) + max(0LL, rem - (1LL << b));
        }
        return count;
    }

    // Helper to count total sum of bit exponents in numbers 1..N
    long long sumBitsUpTo(long long N)
    {
        long long totalSum = 0;
        for (int b = 0; (1LL << b) <= N; ++b)
        {
            long long period = 1LL << (b + 1);
            long long full = (N + 1) / period;
            long long rem = (N + 1) % period;
            long long setBitsAtB = full * (1LL << b) + max(0LL, rem - (1LL << b));
            totalSum += setBitsAtB * b;
        }
        return totalSum;
    }

    // Helper to get total sum of exponents for first (K + 1) elements in the big array
    long long getExpSum(long long K)
    {
        if (K < 0)
            return 0;

        long long low = 1, high = K + 1;
        long long N = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (countBitsUpTo(mid) <= K + 1)
            {
                N = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        long long count = countBitsUpTo(N);
        long long totalExpSum = sumBitsUpTo(N);
        long long rem = (K + 1) - count;

        if (rem > 0)
        {
            long long nextNum = N + 1;
            for (int b = 0; b < 60 && rem > 0; ++b)
            {
                if ((nextNum >> b) & 1)
                {
                    totalExpSum += b;
                    rem--;
                }
            }
        }

        return totalExpSum;
    }

    long long power(long long base, long long exp, long long mod)
    {
        if (mod == 1)
            return 0; // Special case: any integer % 1 is 0

        long long res = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (__int128)res * base % mod;
            base = (__int128)base * base % mod;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> findProductsOfElements(vector<vector<long long>> &queries)
    {
        vector<int> ans;
        for (const auto &q : queries)
        {
            long long from = q[0];
            long long to = q[1];
            long long mod = q[2];

            long long expSum = getExpSum(to) - getExpSum(from - 1);
            ans.push_back(power(2, expSum, mod));
        }
        return ans;
    }
};