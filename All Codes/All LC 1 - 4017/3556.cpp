// Link: https://leetcode.com/problems/sum-of-largest-prime-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * sqrt(m)) where n is the length of the string and m is the maximum number formed by the substring.
    // SC: O(1)
    // Approach:
    //  1. Iterate over all possible substrings of the input string s.
    //  2. For each substring, check if it is a prime number using the is_prime function.
    //  3. If it is a prime number, add it to a vector of primes.
    //  4. Sort the vector of primes in descending order and keep only the top 3 largest primes.
    //  5. Finally, return the sum of the largest primes.
    long long sumOfLargestPrimes(std::string s)
    {
        const auto size = s.size();
        std::vector<long long> primes;
        primes.reserve(4);
        for (auto i = size; i > 0 && primes.size() < 3; --i)
        {
            const auto nested_size = size - i + 1;
            for (auto j = 0; j < nested_size; ++j)
            {
                if (s[j] == '0')
                {
                    continue;
                }
                const long long cur = std::stoll(s.substr(j, i));
                if (is_prime(cur))
                {
                    const auto search = std::lower_bound(primes.begin(), primes.end(), cur, std::greater{});
                    if (search == primes.end() || *search != cur)
                    {
                        primes.insert(search, cur);
                    }
                    primes.resize(std::min(primes.size(), size_t(3)));
                }
            }
        }

        long long sum = 0;
        for (const auto p : primes)
        {
            sum += p;
        }
        return sum;
    }

    bool is_prime(long long n)
    {
        if (n == 1)
        {
            return false;
        }

        if (n <= 3)
        {
            return true;
        }

        if (n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }

        long long d = 5;
        while (d * d <= n)
        {
            if (n % d == 0 || n % (d + 2) == 0)
            {
                return false;
            }
            d += 6;
        }
        return true;
    }
};