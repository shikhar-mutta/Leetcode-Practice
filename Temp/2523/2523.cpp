// Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isComposite(right + 1, false);
        vector<int> primes;
        for (int i = 2; i <= right; i++) {
            if (!isComposite[i]) {
                if (i >= left) primes.push_back(i);
                for (long long j = (long long)i * i; j <= right; j += i)
                    isComposite[j] = true;
            }
        }

        vector<int> ans = {-1, -1};
        int best = INT_MAX;
        for (int i = 1; i < (int)primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if (diff < best) {
                best = diff;
                ans = {primes[i-1], primes[i]};
            }
        }
        return ans;
    }
};
