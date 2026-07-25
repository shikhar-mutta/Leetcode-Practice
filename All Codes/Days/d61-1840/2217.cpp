// Link: https://leetcode.com/problems/find-palindrome-with-fixed-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(queries.size() * intLength)
// SC: O(1) extra beyond the output
// Approach: a palindrome of length intLength is fully determined by its
// first half (ceil(intLength/2) digits, no leading zero), so there are
// exactly 9 * 10^(halfLen-1) such palindromes, ordered the same way their
// half is ordered numerically. For query q, the k-th half is simply
// start + (q-1); mirror those digits back (skipping the middle digit once
// more for odd lengths) to build the full palindrome. If q exceeds the
// total count, no such palindrome exists.
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int halfLen = (intLength + 1) / 2;
        long long start = pow(10, halfLen - 1);
        long long count = 9 * start; // total palindromes of this length

        vector<long long> res;
        res.reserve(queries.size());
        for (int q : queries) {
            if (q > count) {
                res.push_back(-1);
                continue;
            }

            long long half = start + (q - 1);
            long long pal = half;
            // mirror the half onto the full palindrome
            long long h = half;
            if (intLength % 2)
                h /= 10; // odd length: skip the middle digit
            while (h) {
                pal = pal * 10 + h % 10;
                h /= 10;
            }
            res.push_back(pal);
        }
        return res;
    }
};
