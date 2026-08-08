// Link: https://leetcode.com/problems/prime-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        for (int len = 1; ; len++) {
            long long start = 1;
            for (int i = 1; i < len; i++) start *= 10;
            long long end = start * 10;
            for (long long half = start; half < end; half++) {
                string h = to_string(half);
                string full = h;
                for (int i = h.size() - 2; i >= 0; i--) full += h[i];
                long long val = stoll(full);
                if (val >= n && isPrime(val)) return (int)val;
            }
            // also odd-digit case handled by half construction; try even length by mirroring fully
        }
    }

private:
    bool isPrime(long long x) {
        if (x < 2) return false;
        for (long long i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }
};
