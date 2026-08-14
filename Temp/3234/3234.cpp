// Link: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeroPos;
        for (int i = 0; i < n; i++) if (s[i] == '0') zeroPos.push_back(i);
        int m = zeroPos.size();

        long long ans = 0;

        // z = 0: substrings entirely of ones
        {
            int i = 0;
            while (i < n) {
                if (s[i] == '1') {
                    int j = i;
                    while (j < n && s[j] == '1') j++;
                    long long len = j - i;
                    ans += len * (len + 1) / 2;
                    i = j;
                } else i++;
            }
        }

        for (long long z = 1; z + z * z <= n; z++) {
            for (int i = 0; i + z - 1 < m; i++) {
                int leftLimit = (i == 0) ? -1 : zeroPos[i - 1];
                long long A = zeroPos[i] - leftLimit;
                int endIdx = i + (int)z - 1;
                int rightLimit = (endIdx + 1 == m) ? n : zeroPos[endIdx + 1];
                long long B = rightLimit - zeroPos[endIdx];
                long long baseLen = zeroPos[endIdx] - zeroPos[i] + 1;
                long long need = z + z * z - baseLen;
                if (need <= 0) {
                    ans += A * B;
                    continue;
                }
                // count pairs (a in [0,A-1], b in [0,B-1]) with a+b>=need
                long long lowA = max(0LL, need - B);
                long long highA = min(A - 1, need - 1);
                if (lowA <= highA) {
                    long long cnt = highA - lowA + 1;
                    long long sumA = (lowA + highA) * cnt / 2;
                    ans += cnt * (B - need) + sumA;
                }
                if (need <= A - 1) {
                    long long cnt2 = (A - 1) - need + 1;
                    ans += cnt2 * B;
                }
            }
        }

        return (int)ans;
    }
};
