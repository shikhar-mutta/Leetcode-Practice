// Link: https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(maxVal) log sqrt(maxVal)) sieve, amortized O(log) per query
// Approach: A number is "special" iff it has exactly 2 divisors' worth of
// structure squared, i.e. it equals p^2 for a prime p. So count primes p
// with l <= p^2 <= r (equivalently sqrt(l) <= p <= sqrt(r)) via a
// precomputed sieve up to sqrt(1e9) and binary search; answer is the total
// range size minus that special count.
class Solution {
    static bool precompute;
    static int size;
    static vector<int> primes;
    int binarySearch(vector<int>& nums, int target, int size) {
        int i = 0, j = size - 1, result = 0;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target) {
                result = mid;
                i = mid + 1;
            } else
                j = mid - 1;
        }
        return result;
    }
    void seiveOfEranthoses(vector<int>& primes) {
        const int LIMIT = sqrt(1e9) + 1;
        vector<bool> isPrime(LIMIT, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < LIMIT; i++) {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j < LIMIT; j += i)
                isPrime[j] = false;
        }
        for (int i = 2; i < LIMIT; ++i)
            if (isPrime[i])
                primes.push_back(i);
    }

public:
    int nonSpecialCount(int l, int r) {
        if (!precompute) {
            seiveOfEranthoses(primes);
            precompute = true;
            size = primes.size();
        }
        int left = sqrt((l == 1 ? (l + 1) : l)), right = sqrt(r);
        if (left * left != l)
            ++left;
        int special = upper_bound(primes.begin(), primes.end(), right) -
                      lower_bound(primes.begin(), primes.end(), left);
        int total = r - l + 1;
        return (total - special);
    }
};
bool Solution::precompute = false;
int Solution::size;
vector<int> Solution::primes;
