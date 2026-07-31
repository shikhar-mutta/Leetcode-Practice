// Link: https://leetcode.com/problems/split-array-by-prime-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++) if (x % i == 0) return false;
        return true;
    }

    long long splitArray(vector<int>& nums) {
        long long sumA = 0, sumB = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (isPrime(i)) sumA += nums[i];
            else sumB += nums[i];
        }
        return llabs(sumA - sumB);
    }
};
