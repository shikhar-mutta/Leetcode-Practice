// Link: https://leetcode.com/problems/find-the-closest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(len)  SC: O(len)
// Approach: any nearest palindrome (other than n itself) comes from one
// of a small candidate set: mirror the left half of n as-is, mirror the
// left half incremented by 1, mirror the left half decremented by 1, or
// the boundary values 10^(len-1)-1 (all 9's, one digit shorter) and
// 10^(len-1)+1 (power of 10 plus 1, one digit longer). Pick the closest
// candidate != n, breaking ties toward the smaller value.
class Solution {
    string mirror(string half, int len, bool odd) {
        string res = half;
        string tail = half;
        if (odd) tail.pop_back();
        reverse(tail.begin(), tail.end());
        res += tail;
        return res;
    }
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;

        candidates.insert((long long)pow(10, len - 1) - 1);
        candidates.insert((long long)pow(10, len) + 1);

        bool odd = (len % 2 == 1);
        int halfLen = (len + 1) / 2;
        long long half = stoll(n.substr(0, halfLen));

        for (long long h : {half - 1, half, half + 1}) {
            if (h < 0) continue;
            string hs = to_string(h);
            candidates.insert(stoll(mirror(hs, len, odd)));
        }

        long long best = -1;
        for (long long c : candidates) {
            if (c == num) continue;
            if (best == -1) { best = c; continue; }
            long long diff1 = llabs(c - num), diff2 = llabs(best - num);
            if (diff1 < diff2 || (diff1 == diff2 && c < best)) best = c;
        }
        return to_string(best);
    }
};
