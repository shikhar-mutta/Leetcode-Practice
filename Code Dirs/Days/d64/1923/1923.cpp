// Link: https://leetcode.com/problems/longest-common-subpath/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum(len) * log(minLen))  SC: O(maxLen)
// Approach: binary search on answer length L. For each L, compute the set of
// rolling-hash values of all length-L windows in the first path, then
// intersect with each subsequent path's window hashes; feasible if the
// intersection stays non-empty across all paths.
class Solution {
    const long long MOD = 2305843009213693951LL; // large prime
    long long base;

    unordered_set<long long> hashesOfLength(vector<int>& path, int L, vector<long long>& powBase) {
        unordered_set<long long> res;
        int n = path.size();
        if (L > n) return res;
        long long h = 0;
        for (int i = 0; i < L; i++) h = (h * base + path[i]) % MOD;
        res.insert(h);
        for (int i = L; i < n; i++) {
            h = (h - path[i-L] * powBase[L-1] % MOD + MOD) % MOD;
            h = (h * base + path[i]) % MOD;
            res.insert(h);
        }
        return res;
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        base = 131542391;
        int minLen = INT_MAX;
        for (auto& p : paths) minLen = min(minLen, (int)p.size());
        vector<long long> powBase(minLen + 1);
        powBase[0] = 1;
        for (int i = 1; i <= minLen; i++) powBase[i] = powBase[i-1] * base % MOD;

        auto feasible = [&](int L) {
            if (L == 0) return true;
            unordered_set<long long> common = hashesOfLength(paths[0], L, powBase);
            for (size_t i = 1; i < paths.size(); i++) {
                auto cur = hashesOfLength(paths[i], L, powBase);
                unordered_set<long long> next;
                for (long long h : cur) if (common.count(h)) next.insert(h);
                common = next;
                if (common.empty()) return false;
            }
            return !common.empty();
        };

        int lo = 0, hi = minLen, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
