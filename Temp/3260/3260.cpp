// Link: https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindrome(int n, int k) {
        int half = (n + 1) / 2;

        vector<int> pow10(n);
        pow10[0] = 1 % k;
        for (int i = 1; i < n; i++) pow10[i] = (pow10[i-1] * 10) % k;

        vector<int> coeff(half);
        for (int pos = 0; pos < half; pos++) {
            int mirrorPos = n - 1 - pos;
            if (mirrorPos == pos) coeff[pos] = pow10[pos];
            else coeff[pos] = (pow10[pos] + pow10[mirrorPos]) % k;
        }

        // feasible[pos][R] = can positions [pos..half-1] contribute exactly R (mod k)
        vector<vector<char>> feasible(half + 1, vector<char>(k, 0));
        feasible[half][0] = 1;
        for (int pos = half - 1; pos >= 0; pos--) {
            int dMin = (pos == 0) ? 1 : 0;
            for (int R = 0; R < k; R++) {
                bool ok = false;
                for (int d = dMin; d <= 9 && !ok; d++) {
                    int contribution = (d * coeff[pos]) % k;
                    int nextR = ((R - contribution) % k + k) % k;
                    if (feasible[pos+1][nextR]) ok = true;
                }
                feasible[pos][R] = ok ? 1 : 0;
            }
        }

        string halfDigits(half, '0');
        int acc = 0;
        for (int pos = 0; pos < half; pos++) {
            int dMin = (pos == 0) ? 1 : 0;
            for (int d = 9; d >= dMin; d--) {
                int contribution = (d * coeff[pos]) % k;
                int newAcc = (acc + contribution) % k;
                int neededR = (k - newAcc) % k;
                if (feasible[pos+1][neededR]) {
                    halfDigits[pos] = '0' + d;
                    acc = newAcc;
                    break;
                }
            }
        }

        string result(n, '0');
        for (int i = 0; i < n; i++) {
            if (i < half) result[i] = halfDigits[i];
            else result[i] = halfDigits[n-1-i];
        }
        return result;
    }
};
