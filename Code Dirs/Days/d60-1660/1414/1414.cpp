// Link: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(k)) where k is the input number.
    // SC: O(log(k)) where k is the input number.
    //  Approach:
    //    1. We will generate all the Fibonacci numbers less than or equal to k.
    //    2. We will use a greedy approach to find the minimum number of Fibonacci numbers whose sum is k. We will start from the largest Fibonacci number and subtract it from k until k becomes zero. We will keep track of the count of Fibonacci numbers used in the process.
    //    3. We will return the count of Fibonacci numbers used in the process.
    //    4. We will use binary search to find the largest Fibonacci number less than or equal to k in each iteration.
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fib = {1, 1};
        int i = 0;
        int cur = fib[i] + fib[i + 1];
        while (cur <= 1e9)
        {
            fib.push_back(cur);
            i++;
            cur = fib[i] + fib[i + 1];
        }
        int ans = 0;
        while (k)
        {
            auto it = lower_bound(fib.begin(), fib.end(), k);
            if (*it == k)
            {
                ans++;
                break;
            }
            ans++;
            it--;
            k -= *it;
        }
        return ans;
    }
};
