// Link: https://leetcode.com/problems/find-palindrome-with-fixed-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int halfLen = (intLength + 1) / 2;
        long long minHalf = 1;
        for (int i = 1; i < halfLen; i++) minHalf *= 10;
        long long maxHalf = minHalf * 10 - 1;

        vector<long long> res;
        for (int q : queries) {
            long long half = minHalf + (q - 1);
            if (half > maxHalf) { res.push_back(-1); continue; }
            string hs = to_string(half);
            string rev = hs;
            reverse(rev.begin(), rev.end());
            string full = hs;
            if (intLength % 2 == 0) full += rev;
            else full += rev.substr(1);
            res.push_back(stoll(full));
        }
        return res;
    }
};
