// Link: https://leetcode.com/problems/longest-common-subpath/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e18 + 9;
    const long long BASE = 131;

    unordered_set<long long> getHashes(vector<int>& path, int len, vector<long long>& pw) {
        unordered_set<long long> hashes;
        int n = path.size();
        if (len > n) return hashes;
        long long h = 0;
        for (int i = 0; i < len; i++) h = (__int128)(h * BASE + path[i] + 1) % MOD;
        hashes.insert(h);
        for (int i = len; i < n; i++) {
            h = (__int128)(h * BASE + path[i] + 1) % MOD;
            h = ((__int128)h - (__int128)(path[i-len]+1) * pw[len] % MOD + MOD) % MOD;
            hashes.insert(h);
        }
        return hashes;
    }

    bool check(vector<vector<int>>& paths, int len, vector<long long>& pw) {
        auto common = getHashes(paths[0], len, pw);
        for (int i = 1; i < (int)paths.size(); i++) {
            auto cur = getHashes(paths[i], len, pw);
            unordered_set<long long> next;
            for (long long h : common) if (cur.count(h)) next.insert(h);
            common = next;
            if (common.empty()) return false;
        }
        return !common.empty();
    }

    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int maxLen = paths[0].size();
        for (auto& p : paths) maxLen = min(maxLen, (int)p.size());

        vector<long long> pw(maxLen + 1);
        pw[0] = 1;
        for (int i = 1; i <= maxLen; i++) pw[i] = (__int128)pw[i-1] * BASE % MOD;

        int lo = 0, hi = maxLen;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (check(paths, mid, pw)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
