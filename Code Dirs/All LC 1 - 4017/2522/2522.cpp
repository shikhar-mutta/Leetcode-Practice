// Link: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int parts = 1;
        long long cur = 0;
        for (char c : s) {
            int d = c - '0';
            if (d > k) return -1;
            long long next = cur * 10 + d;
            if (next > k) {
                parts++;
                cur = d;
            } else {
                cur = next;
            }
        }
        return parts;
    }
};
