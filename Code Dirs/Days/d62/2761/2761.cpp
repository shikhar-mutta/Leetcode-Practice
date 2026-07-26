// Link: https://leetcode.com/problems/prime-pairs-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log log N) one-time sieve (shared/static across calls) + O(pi(n))
// per call
// SC: O(N) for the shared sieve
// Approach: static sieve up to 1e6, computed once and reused across all
// instances/calls. For a given n, walk the primes list; for each prime p <=
// n/2, check if n-p is also prime (via the isPrime lookup) and collect the
// pair. Stop once p exceeds n-p to avoid duplicate/reversed pairs.
class Solution {
public:
    static const int N = 1000000;
    static vector<bool> isPrime;
    static vector<int> primes;
    static bool done;

    void sieve() {
        if (done)
            return;
        done = true;

        isPrime.assign(N + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= N; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
    }

    vector<vector<int>> findPrimePairs(int n) {
        sieve();

        vector<vector<int>> ans;

        for (int p : primes) {
            if (p > n - p)
                break;

            if (isPrime[n - p]) {
                ans.push_back({p, n - p});
            }
        }

        return ans;
    }
};

vector<bool> Solution::isPrime;
vector<int> Solution::primes;
bool Solution::done = false;
