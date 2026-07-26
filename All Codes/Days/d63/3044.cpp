// Link: https://leetcode.com/problems/most-frequent-prime/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*max(m,n)*sqrt(maxVal)), SC: O(distinct primes formed)
// Approach: From every cell, walk in all 8 directions building the number
// digit-by-digit (curr = curr*10 + digit) as far as the grid allows. Any
// resulting value > 10 that's prime gets counted; return the prime with the
// highest frequency, breaking ties by picking the larger value.
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> counts;
        int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int d = 0; d < 8; ++d) {
                    int curr = mat[i][j];
                    int r = i + dr[d];
                    int c = j + dc[d];
                    while (r >= 0 && r < m && c >= 0 && c < n) {
                        curr = curr * 10 + mat[r][c];
                        if (curr > 10 && isPrime(curr)) {
                            counts[curr]++;
                        }
                        r += dr[d];
                        c += dc[d];
                    }
                }
            }
        }

        int maxFreq = 0;
        int bestPrime = -1;
        for (auto const& [val, freq] : counts) {
            if (freq > maxFreq) {
                maxFreq = freq;
                bestPrime = val;
            } else if (freq == maxFreq) {
                if (val > bestPrime) {
                    bestPrime = val;
                }
            }
        }

        return bestPrime;
    }
};
