// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int SZ = 26;
    const long long MOD = 1000000007;

    using Mat = array<array<long long, SZ>, SZ>;

    Mat matMul(const Mat& A, const Mat& B) {
        Mat C{};
        for (int i = 0; i < SZ; i++) {
            for (int k = 0; k < SZ; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < SZ; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Mat matPow(Mat M, long long p) {
        Mat result{};
        for (int i = 0; i < SZ; i++) result[i][i] = 1;
        while (p > 0) {
            if (p & 1) result = matMul(result, M);
            M = matMul(M, M);
            p >>= 1;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat M{};
        for (int c = 0; c < SZ; c++) {
            for (int i = 1; i <= nums[c]; i++) {
                int d = (c + i) % SZ;
                M[c][d] += 1;
            }
        }

        Mat Mt = matPow(M, t);

        // v_t[c] = sum_d Mt[c][d] * v0[d], v0 all ones
        vector<long long> vt(SZ, 0);
        for (int c = 0; c < SZ; c++) {
            long long sum = 0;
            for (int d = 0; d < SZ; d++) sum += Mt[c][d];
            vt[c] = sum % MOD;
        }

        long long ans = 0;
        for (char c : s) ans = (ans + vt[c - 'a']) % MOD;
        return (int)ans;
    }
};
