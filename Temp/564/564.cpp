// Link: https://leetcode.com/problems/find-the-closest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len)  SC: O(len)
// Approach: generate candidates - mirror of the prefix, mirror of
// (prefix+1), mirror of (prefix-1), plus the boundary cases 10^(k-1)-1 and
// 10^k+1; pick the closest, ties broken toward the smaller value
class Solution {
    long long mirror(long long prefix, int len, bool odd) {
        string p = to_string(prefix);
        string suffix = p;
        if (odd) suffix.pop_back();
        reverse(suffix.begin(), suffix.end());
        return stoll(p + suffix);
    }

public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;

        candidates.insert((long long)pow(10, len - 1) - 1);
        candidates.insert((long long)pow(10, len) + 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        bool odd = len % 2 == 1;
        for (long long p : {prefix - 1, prefix, prefix + 1}) {
            if (p < 0) continue;
            candidates.insert(mirror(p, len, odd));
        }
        candidates.erase(num);

        long long best = -1;
        for (long long c : candidates) {
            if (best == -1) { best = c; continue; }
            long long diff = abs(c - num), bestDiff = abs(best - num);
            if (diff < bestDiff || (diff == bestDiff && c < best)) best = c;
        }
        return to_string(best);
    }
};
