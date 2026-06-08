// Link: https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * sqrt(m)). SC: O(n)
    bool checkPrimeFrequency(vector<int> &nums)
    {
        auto isPrime = [](int n)
        {
            if (n <= 1)
                return false;
            if (n <= 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
            for (int i = 5; i * i <= n; i += 6)
            {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        for (const auto &pair : freq)
            if (isPrime(pair.second))
                return true;

        return false;
    }
};
