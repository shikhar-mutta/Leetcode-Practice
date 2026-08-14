// Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long,long long> cntG;
        for (int x : nums) {
            long long g = gcd((long long)x, (long long)k);
            cntG[g]++;
        }
        vector<long long> divisors;
        for (long long d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                divisors.push_back(d);
                if (d != k / d) divisors.push_back(k / d);
            }
        }
        long long total = 0;
        int m = divisors.size();
        for (int i = 0; i < m; i++) {
            long long d1 = divisors[i];
            if (!cntG.count(d1)) continue;
            for (int j = i; j < m; j++) {
                long long d2 = divisors[j];
                if (!cntG.count(d2)) continue;
                if ((d1 * d2) % k != 0) continue;
                if (d1 == d2) {
                    long long c = cntG[d1];
                    total += c * (c - 1) / 2;
                } else {
                    total += cntG[d1] * cntG[d2];
                }
            }
        }
        return total;
    }
};
