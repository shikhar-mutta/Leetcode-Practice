// Link: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(maxVal))
// SC: O(number of distinct primes found)
// Approach: the product's prime factors are just the union of every
// element's prime factors, so trial-divide each element up to sqrt(n)
// and collect every prime divisor into a set; the answer is the set's
// size.
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;

        for (int n : nums) {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    st.insert(i);

                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }

            if (n > 1)
                st.insert(n);
        }

        return st.size();
    }
};
