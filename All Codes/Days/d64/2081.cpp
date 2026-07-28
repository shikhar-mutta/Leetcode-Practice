// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * digits) amortized  SC: O(digits)
// Approach: generate base-10 palindromes in increasing order by building
// from a "half" prefix of increasing length and mirroring it (odd length
// drops the middle digit when mirroring). For each, check if its base-k
// representation is also a palindrome; sum until n found.
class Solution {
    bool isKPalindrome(long long num, int k) {
        vector<int> digits;
        while (num > 0) { digits.push_back(num % k); num /= k; }
        int l = 0, r = (int)digits.size() - 1;
        while (l < r) { if (digits[l] != digits[r]) return false; l++; r--; }
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long total = 0;
        int found = 0;
        for (int len = 1; found < n; len++) {
            int halfLen = (len + 1) / 2;
            long long start = 1;
            for (int i = 1; i < halfLen; i++) start *= 10;
            long long end = start * 10;
            for (long long half = start; half < end && found < n; half++) {
                string h = to_string(half);
                string full = h;
                string rev = h;
                reverse(rev.begin(), rev.end());
                if (len % 2 == 0) full += rev;
                else full += rev.substr(1);
                long long num = stoll(full);
                if (isKPalindrome(num, k)) {
                    total += num;
                    found++;
                }
            }
        }
        return total;
    }
};
