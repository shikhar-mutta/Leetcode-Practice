// Link: https://leetcode.com/problems/the-kth-factor-of-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(n)), SC: O(sqrt(n))
    //     Approach:
    //     1. Initialize an empty vector small to store the factors of n that are less than or equal to the square root of n.
    //     2. Iterate through all integers d from 1 to the square root of n (inclusive).
    //     3. For each integer d, check if it is a factor of n (i.e., n % d == 0). If it is, decrement k. If k becomes 0, return d as the k-th factor.
    //     4. If d is a factor, add it to the small vector.
    //     5. After iterating through all integers up to the square  root of n, check if n is a perfect square. If it is, skip the square root factor when counting the larger factors.
    //     6. Iterate through the small vector in reverse order to find the larger factors of n (i.e., n / small[i]). For each larger factor, decrement k. If k becomes 0, return the larger factor as the k-th factor.
    //     7. If k is still greater than 0 after checking all factors, return -1 to indicate that there are fewer than k factors of n.
    int kthFactor(int n, int k)
    {
        vector<int> small;
        int d = 1;
        for (; (long long)d * d <= n; ++d)
        {
            if (n % d)
                continue;
            if (--k == 0)
                return d;
            small.push_back(d);
        }
        // walk complements in increasing order, skipping sqrt if n is a perfect
        // square
        int start = small.size() - 1;
        if (!small.empty() && (long long)small.back() * small.back() == n)
            --start;
        for (int i = start; i >= 0; --i)
        {
            if (--k == 0)
                return n / small[i];
        }
        return -1;
    }
};