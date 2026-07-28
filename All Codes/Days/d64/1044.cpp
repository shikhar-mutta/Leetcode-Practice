// Link: https://leetcode.com/problems/longest-duplicate-substring/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n) expected  SC: O(n)
// Approach: binary search on the candidate length L. For each L, use a
// rolling polynomial hash (Rabin-Karp) to check in O(n) whether any two
// substrings of length L share the same hash (verified by direct string
// comparison to guard against collisions), keeping the longest found.
class Solution {
    string search(const string& s, int L) {
        int n = s.size();
        if (L == 0) return "";
        const long long MOD = 1000000007LL;
        const long long BASE = 26;
        long long h = 0, power = 1;
        for (int i = 0; i < L; i++) {
            h = (h * BASE + (s[i] - 'a')) % MOD;
            if (i < L - 1) power = (power * BASE) % MOD;
        }
        unordered_map<long long, vector<int>> seen;
        seen[h].push_back(0);
        for (int i = 1; i + L <= n; i++) {
            h = (h - (long long)(s[i - 1] - 'a') * power % MOD + MOD) % MOD;
            h = (h * BASE + (s[i + L - 1] - 'a')) % MOD;
            if (seen.count(h)) {
                for (int j : seen[h]) {
                    if (s.compare(j, L, s, i, L) == 0) return s.substr(i, L);
                }
            }
            seen[h].push_back(i);
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int lo = 1, hi = n - 1;
        string best = "";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            string found = search(s, mid);
            if (!found.empty()) {
                best = found;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
