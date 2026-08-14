// Link: https://leetcode.com/problems/count-number-of-texts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        const long long MOD = 1e9 + 7;
        int n = pressedKeys.size();
        int maxLen = 100;
        vector<long long> f3(maxLen + 1, 0), f4(maxLen + 1, 0);
        f3[0] = f4[0] = 1;
        f3[1] = f4[1] = 1;
        f3[2] = f4[2] = 2;
        f3[3] = f4[3] = 4;
        f4[3] = 4;
        for (int i = 3; i <= maxLen; i++) {
            f3[i] = (f3[i-1] + f3[i-2] + f3[i-3]) % MOD;
        }
        for (int i = 4; i <= maxLen; i++) {
            f4[i] = (f4[i-1] + f4[i-2] + f4[i-3] + f4[i-4]) % MOD;
        }

        long long result = 1;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && pressedKeys[j] == pressedKeys[i]) j++;
            int len = j - i;
            char c = pressedKeys[i];
            if (c == '7' || c == '9') result = (result * f4[len]) % MOD;
            else result = (result * f3[len]) % MOD;
            i = j;
        }
        return (int)result;
    }
};
