// Link: https://leetcode.com/problems/super-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sqrt(maxVal))  SC: O(1)
// Approach: a super-palindrome's square root must itself be a palindrome
// (since a perfect square that's a palindrome... actually we directly
// generate candidate roots by building palindromes from half-strings
// (both odd and even length), since roots only need to go up to
// sqrt(right) ~ 1e9. Square each candidate root and check if the square
// is itself a palindrome and within [left, right].
class Solution {
    bool isPalindrome(const string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) if (s[i] != s[n - 1 - i]) return false;
        return true;
    }
public:
    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left), R = stoll(right);
        long long count = 0;

        for (int half = 1; half <= 100000; half++) {
            string h = to_string(half);
            // odd-length palindrome root: h + reverse(h without last char)
            string revOdd = h;
            revOdd.pop_back();
            reverse(revOdd.begin(), revOdd.end());
            string oddRoot = h + revOdd;

            // even-length palindrome root: h + reverse(h)
            string revEven = h;
            reverse(revEven.begin(), revEven.end());
            string evenRoot = h + revEven;

            for (const string& rootStr : {oddRoot, evenRoot}) {
                long long root = stoll(rootStr);
                long long sq = root * root;
                if (sq > R) continue;
                if (sq < L) continue;
                string sqStr = to_string(sq);
                if (isPalindrome(sqStr)) count++;
            }
        }
        return (int)count;
    }
};
