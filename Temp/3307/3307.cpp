// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int m = operations.size();
        const long long CAP = 200000000000000LL; // 2e14, safely above max k (1e14)
        vector<long long> lengths(m + 1);
        lengths[0] = 1;
        for (int i = 1; i <= m; i++) {
            lengths[i] = (lengths[i-1] >= CAP) ? CAP : lengths[i-1] * 2;
            if (lengths[i] > CAP) lengths[i] = CAP;
        }

        long long pos = k - 1;
        int shift = 0;
        for (int i = m - 1; i >= 0; i--) {
            long long half = lengths[i];
            if (pos >= half) {
                pos -= half;
                if (operations[i] == 1) shift++;
            }
        }

        return (char)('a' + (shift % 26));
    }
};
