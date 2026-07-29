// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26^3 log t + N), SC: O(26^2)
// Approach: each round is a fixed linear map on the 26-dim vector of per-letter counts: letter c
// contributes to letters c, c+1, ..., c+nums[c]-1 (mod 26). Build that 26x26 transition matrix
// and raise it to the t-th power via fast exponentiation, then apply it to the initial letter
// count vector from s; the answer is the sum of the resulting counts.
class Solution {
public:
    const long long MOD = 1e9+7;
    using Mat = vector<vector<long long>>;

    Mat multiply(const Mat& a, const Mat& b) {
        int n = a.size();
        Mat c(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++) {
                if (!a[i][k]) continue;
                for (int j = 0; j < n; j++)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        return c;
    }

    Mat matPow(Mat m, long long e) {
        int n = m.size();
        Mat r(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) r[i][i] = 1;
        while (e > 0) {
            if (e & 1) r = multiply(r, m);
            m = multiply(m, m);
            e >>= 1;
        }
        return r;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat M(26, vector<long long>(26, 0));
        for (int c = 0; c < 26; c++) {
            for (int i = 1; i <= nums[c]; i++) M[(c + i) % 26][c] = 1;
        }
        Mat Mt = matPow(M, t);

        vector<long long> cnt(26, 0);
        for (char c : s) cnt[c-'a']++;

        vector<long long> res(26, 0);
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                res[i] = (res[i] + Mt[i][j] * cnt[j]) % MOD;

        long long ans = 0;
        for (long long x : res) ans = (ans + x) % MOD;
        return (int)ans;
    }
};
