// Link: https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*k), SC: O(N*k)
// Approach: a palindrome of length n is fully determined by its first half's digits (position i
// mirrors to n-1-i). Precompute each position's "weight" (its contribution to the value mod k
// when set to 1), then a backward feasibility DP: feasible[pos][r] = can the remaining positions
// be filled so the total remainder becomes 0, given partial remainder r after position pos-1.
// Greedily build the answer left to right, picking the largest digit at each position that keeps
// the rest feasible.
class Solution {
public:
    string largestPalindrome(int n, int k) {
        int half = (n + 1) / 2;
        vector<long long> weight(half, 0);
        vector<long long> pow10(n, 0);
        pow10[0] = 1 % k;
        for (int i = 1; i < n; i++) pow10[i] = (pow10[i-1] * 10) % k;

        for (int i = 0; i < half; i++) {
            if (i == n - 1 - i) weight[i] = pow10[i]; // middle digit (n odd)
            else weight[i] = (pow10[i] + pow10[n-1-i]) % k;
        }

        vector<vector<char>> feasible(half + 1, vector<char>(k, 0));
        feasible[half][0] = 1;
        for (int pos = half - 1; pos >= 0; pos--) {
            for (int r = 0; r < k; r++) {
                bool ok = false;
                int lo = (pos == 0) ? 1 : 0;
                for (int d = lo; d <= 9 && !ok; d++) {
                    int nr = (int)((r + d * weight[pos]) % k);
                    if (feasible[pos+1][nr]) ok = true;
                }
                feasible[pos][r] = ok;
            }
        }

        if (!feasible[0][0]) return "-1";

        string half_s(half, '0');
        int r = 0;
        for (int pos = 0; pos < half; pos++) {
            int lo = (pos == 0) ? 1 : 0;
            for (int d = 9; d >= lo; d--) {
                int nr = (int)((r + d * weight[pos]) % k);
                if (feasible[pos+1][nr]) {
                    half_s[pos] = '0' + d;
                    r = nr;
                    break;
                }
            }
        }

        string result(n, '0');
        for (int i = 0; i < half; i++) {
            result[i] = half_s[i];
            result[n-1-i] = half_s[i];
        }
        return result;
    }
};
