// Link: https://leetcode.com/problems/count-special-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perm(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long r = 1;
        for (int i = 0; i < k; i++) r *= (n - i);
        return r;
    }

    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.size();
        long long count = 0;

        for (int L = 1; L < len; L++) {
            count += 9 * perm(9, L - 1);
        }

        vector<bool> used(10, false);
        bool completed = true;
        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int d = start; d < digit; d++) {
                if (used[d]) continue;
                count += perm(9 - i, len - 1 - i);
            }
            if (used[digit]) { completed = false; break; }
            used[digit] = true;
        }
        if (completed) count++;
        return (int)count;
    }
};
