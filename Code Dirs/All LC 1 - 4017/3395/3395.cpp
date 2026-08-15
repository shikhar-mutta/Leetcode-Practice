// Link: https://leetcode.com/problems/subsequences-with-a-unique-middle-mode-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long C2(long long a) { return a >= 2 ? a * (a - 1) / 2 : 0; }
    long long C1(long long a) { return a >= 1 ? a : 0; }

    int subsequencesWithMiddleMode(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end()) + 1;
        vector<long long> L(maxVal + 1, 0), R(maxVal + 1, 0);
        for (int v : nums) R[v]++;

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int x = nums[j];
            R[x]--; // now R represents strictly-after-j counts

            long long Lx = L[x], Rx = R[x];
            long long Ltotal = j, Rtotal = n - 1 - j;
            long long LnonX = Ltotal - Lx, RnonX = Rtotal - Rx;

            // full sums over all values
            long long fullLsumC2 = 0, fullRsumC2 = 0, fullLR1 = 0, fullLR2_R = 0, fullLR2_L = 0;
            for (int y = 0; y <= maxVal; y++) {
                if (L[y] == 0 && R[y] == 0) continue;
                fullLsumC2 += C2(L[y]);
                fullRsumC2 += C2(R[y]);
                fullLR1 += L[y] * R[y];
                fullLR2_R += L[y] * R[y] * R[y];
                fullLR2_L += L[y] * L[y] * R[y];
            }
            long long LsumC2 = fullLsumC2 - C2(Lx);
            long long RsumC2 = fullRsumC2 - C2(Rx);
            long long LR1 = fullLR1 - Lx * Rx;
            long long LR2_R = fullLR2_R - Lx * Rx * Rx;
            long long LR2_L = fullLR2_L - Lx * Lx * Rx;

            long long total = 0;

            // case (lx,rx) = (1,0): m=2, needL=1 from LnonX, needR=2 from RnonX (constrained)
            {
                long long unconstrained = C1(LnonX) * C2(RnonX);
                long long bad = LnonX * RsumC2 + (RnonX * LR1 - LR2_R);
                long long valid = unconstrained - bad;
                if (valid < 0) valid = 0;
                total += C1(Lx) * valid;
            }

            // case (lx,rx) = (0,1): m=2, needL=2 from LnonX (constrained), needR=1 from RnonX
            {
                long long unconstrained = C2(LnonX) * C1(RnonX);
                long long bad = RnonX * LsumC2 + (LnonX * LR1 - LR2_L);
                long long valid = unconstrained - bad;
                if (valid < 0) valid = 0;
                total += C1(Rx) * valid;
            }

            // unconstrained cases: lx+rx >= 2
            auto Cn = [&](long long a, long long k) -> long long {
                if (k == 0) return 1;
                if (k == 1) return C1(a);
                return C2(a);
            };
            // (2,0)
            total += Cn(Lx, 2) * Cn(Rx, 0) * Cn(LnonX, 0) * Cn(RnonX, 2);
            // (0,2)
            total += Cn(Lx, 0) * Cn(Rx, 2) * Cn(LnonX, 2) * Cn(RnonX, 0);
            // (1,1)
            total += Cn(Lx, 1) * Cn(Rx, 1) * Cn(LnonX, 1) * Cn(RnonX, 1);
            // (2,1)
            total += Cn(Lx, 2) * Cn(Rx, 1) * Cn(LnonX, 0) * Cn(RnonX, 1);
            // (1,2)
            total += Cn(Lx, 1) * Cn(Rx, 2) * Cn(LnonX, 1) * Cn(RnonX, 0);
            // (2,2)
            total += Cn(Lx, 2) * Cn(Rx, 2) * Cn(LnonX, 0) * Cn(RnonX, 0);

            ans = (ans + total) % MOD;

            L[x]++;
        }

        return (int)(ans % MOD);
    }
};
