// Link: https://leetcode.com/problems/process-string-with-special-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lens(n);
        long long cur = 0;
        const long long CAP = (long long)4e15;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '%') { /* unchanged */ }
            else if (c == '*') cur = max(0LL, cur - 1);
            else if (c == '#') cur = min(cur * 2, CAP);
            else cur += 1;
            lens[i] = cur;
        }

        long long finalLen = lens[n-1];
        if (k >= finalLen) return '.';

        long long pos = k;
        bool rev = false;
        for (int i = n - 1; i >= 0; i--) {
            long long L = lens[i];
            long long Lprev = (i == 0) ? 0 : lens[i-1];
            char c = s[i];
            if (c == '%') { rev = !rev; continue; }

            long long natPos = rev ? (L - 1 - pos) : pos;

            if (c == '*') {
                pos = natPos;
                rev = false;
            } else if (c == '#') {
                if (natPos >= Lprev) natPos -= Lprev;
                pos = natPos;
                rev = false;
            } else {
                if (natPos == Lprev) return c;
                pos = natPos;
                rev = false;
            }
        }

        return '.';
    }
};
