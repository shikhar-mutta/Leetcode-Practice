// Link: https://leetcode.com/problems/find-substring-with-given-hash-value/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: H(i) = sum val(s[i+t])*power^t for t in [0,k). Relation:
// H(i) = val(s[i]) + power*H(i+1) - val(s[i+k])*power^k (mod m). Compute
// rightmost window directly, then slide left using this recurrence,
// tracking leftmost matching start index.
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long pk = 1;
        for (int i = 0; i < k; i++) pk = (pk * power) % modulo;
        long long h = 0;
        for (int t = 0; t < k; t++) {
            long long v = s[n - k + t] - 'a' + 1;
            long long p = 1;
            for (int u = 0; u < t; u++) p = (p * power) % modulo;
            h = (h + v * p) % modulo;
        }
        int ans = -1;
        if (h == hashValue) ans = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            long long v = s[i] - 'a' + 1;
            long long top = (s[i + k] - 'a' + 1) % modulo;
            h = ((v + power * h - top * pk) % modulo + (long long)modulo * modulo) % modulo;
            if (h == hashValue) ans = i;
        }
        return s.substr(ans, k);
    }
};
