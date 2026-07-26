// Link: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: greedily extend the current substring as long as its numeric
// value stays <= k; as soon as appending the next digit would exceed k,
// cut before it and start a new substring. Any single digit exceeding k
// makes the partition impossible.
class Solution {
public:
    int minimumPartition(string s, int k) {
        long long cur = 0;
        int count = 1; // at least one substring
        for (char c : s) {
            int d = c - '0';
            if (d > k)
                return -1;          // a single digit can't fit
            if (cur * 10 + d > k) { // adding d overflows k: cut here
                ++count;
                cur = d; // start new substring with this digit
            } else {
                cur = cur * 10 + d; // extend current substring
            }
        }
        return count;
    }
};
