// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: Manacher's algorithm on a '#'-separated transform handles both
// odd/even palindromes uniformly. For each palindrome found, record the best
// length ending exactly at its right boundary and starting exactly at its
// left boundary. Running max over these gives, for every split point,
// the longest palindrome fully in the prefix / suffix; answer is the best
// product across all splits.
class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        string t = "#";
        for (char c : s) { t += c; t += '#'; }
        int m = t.size();
        vector<int> p(m, 0);
        int c = 0, r = 0;
        for (int i = 0; i < m; i++) {
            if (i < r) p[i] = min(r - i, p[2*c - i]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1]) p[i]++;
            if (i + p[i] > r) { c = i; r = i + p[i]; }
        }

        vector<int> exactEnd(n, 0), exactStart(n, 0);
        for (int i = 0; i < m; i++) {
            int len = p[i];
            if (len == 0) continue;
            int l = (i - len) / 2;
            int rr = (i + len) / 2 - 1;
            if (rr >= 0 && rr < n) exactEnd[rr] = max(exactEnd[rr], len);
            if (l >= 0 && l < n) exactStart[l] = max(exactStart[l], len);
        }

        vector<int> prefixBest(n, 0), suffixBest(n, 0);
        prefixBest[0] = exactEnd[0];
        for (int i = 1; i < n; i++) prefixBest[i] = max(prefixBest[i-1], exactEnd[i]);
        suffixBest[n-1] = exactStart[n-1];
        for (int i = n - 2; i >= 0; i--) suffixBest[i] = max(suffixBest[i+1], exactStart[i]);

        long long ans = 0;
        for (int k = 0; k + 1 < n; k++) {
            ans = max(ans, (long long)prefixBest[k] * suffixBest[k+1]);
        }
        return ans;
    }
};
