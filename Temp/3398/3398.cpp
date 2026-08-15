// Link: https://leetcode.com/problems/smallest-substring-with-identical-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();

        auto costAlt = [&]() -> int {
            int c0 = 0, c1 = 0; // flips needed to match pattern starting with '0'/'1'
            for (int i = 0; i < n; i++) {
                char expect0 = (i % 2 == 0) ? '0' : '1';
                char expect1 = (i % 2 == 0) ? '1' : '0';
                if (s[i] != expect0) c0++;
                if (s[i] != expect1) c1++;
            }
            return min(c0, c1);
        };

        auto cost = [&](int L) -> long long {
            if (L == 1) return costAlt();
            long long total = 0;
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && s[j] == s[i]) j++;
                int runLen = j - i;
                total += runLen / (L + 1);
                i = j;
            }
            return total;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (cost(mid) <= numOps) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
