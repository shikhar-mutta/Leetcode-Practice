// Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + d^2)  SC: O(d)
//  Approach: We can use a hash map to store the frequency of each gcd(num, k). Then, we can iterate through the distinct gcd values and for each pair of distinct gcd values, we can check if their product is divisible by k. If it is, we can add the product of their frequencies to the total count of pairs. We also need to handle the case where the two gcd values are the same, in which case we can add the combination of their frequencies to the total count of pairs.
class Solution
{
public:
    long long countPairs(std::vector<int> &nums, int k)
    {
        long long totalPairs = 0;
        std::unordered_map<int, long long> gcdCounts;

        // Step 1: Count frequencies of gcd(num, k)
        for (int num : nums)
        {
            int currentGcd = std::gcd(num, k);
            gcdCounts[currentGcd]++;
        }

        // Step 2: Pair up the distinct GCD values
        for (auto it1 = gcdCounts.begin(); it1 != gcdCounts.end(); ++it1)
        {
            long long gcd1 = it1->first;
            long long count1 = it1->second;

            // Case 1: Pairs made of the SAME gcd value
            if ((gcd1 * gcd1) % k == 0)
            {
                totalPairs += (count1 * (count1 - 1)) / 2;
            }

            // Case 2: Pairs made of two DIFFERENT gcd values
            for (auto it2 = std::next(it1); it2 != gcdCounts.end(); ++it2)
            {
                long long gcd2 = it2->first;
                long long count2 = it2->second;

                if ((gcd1 * gcd2) % k == 0)
                {
                    totalPairs += count1 * count2;
                }
            }
        }

        return totalPairs;
    }
};