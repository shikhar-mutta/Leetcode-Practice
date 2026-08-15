// Link: https://leetcode.com/problems/prime-subtraction-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxVal = 1001;
        vector<bool> isComposite(maxVal, false);
        vector<int> primes;
        for (int i = 2; i < maxVal; i++) {
            if (!isComposite[i]) {
                primes.push_back(i);
                for (long long j = (long long)i * i; j < maxVal; j += i) isComposite[j] = true;
            }
        }

        int prev = 0;
        for (int num : nums) {
            int best = num;
            for (int p : primes) {
                if (p >= num) break;
                if (num - p > prev) best = min(best, num - p);
            }
            if (best <= prev) return false;
            prev = best;
        }
        return true;
    }
};
