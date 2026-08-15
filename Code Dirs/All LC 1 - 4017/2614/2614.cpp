// Link: https://leetcode.com/problems/prime-in-diagonal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) best = max(best, nums[i][i]);
            if (isPrime(nums[i][n-1-i])) best = max(best, nums[i][n-1-i]);
        }
        return best;
    }
};
