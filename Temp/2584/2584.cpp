// Link: https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorize(int x) {
        vector<int> primes;
        for (int p = 2; (long long)p * p <= x; p++) {
            if (x % p == 0) {
                primes.push_back(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) primes.push_back(x);
        return primes;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> primeFactors(n);
        unordered_map<int,int> lastOccurrence;

        for (int i = 0; i < n; i++) {
            primeFactors[i] = factorize(nums[i]);
            for (int p : primeFactors[i]) lastOccurrence[p] = i;
        }

        vector<int> farthest(n);
        for (int i = 0; i < n; i++) {
            int reach = i;
            for (int p : primeFactors[i]) reach = max(reach, lastOccurrence[p]);
            farthest[i] = reach;
        }

        int runningMax = 0;
        for (int i = 0; i < n - 1; i++) {
            runningMax = max(runningMax, farthest[i]);
            if (runningMax == i) return i;
        }
        return -1;
    }
};
