// Link: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int MAXV = 1000001;
        vector<int> spf(MAXV, 0);
        for (int i = 2; i < MAXV; i++) {
            if (spf[i] == 0) {
                for (int j = i; j < MAXV; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        auto primeFactors = [&](int x) {
            vector<int> fs;
            while (x > 1) {
                int p = spf[x];
                fs.push_back(p);
                while (x % p == 0) x /= p;
            }
            return fs;
        };

        unordered_map<int, vector<int>> bucket;
        vector<vector<int>> factorsOf(n);
        for (int i = 0; i < n; i++) {
            factorsOf[i] = primeFactors(nums[i]);
            for (int p : factorsOf[i]) bucket[p].push_back(i);
        }

        vector<int> dist(n, -1);
        unordered_set<int> usedPrime;
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front(); q.pop();
            int d = dist[i];

            if (i - 1 >= 0 && dist[i-1] == -1) { dist[i-1] = d+1; q.push(i-1); }
            if (i + 1 < n && dist[i+1] == -1) { dist[i+1] = d+1; q.push(i+1); }

            int v = nums[i];
            if (v >= 2 && spf[v] == v) { // nums[i] is itself prime
                int p = v;
                if (!usedPrime.count(p)) {
                    usedPrime.insert(p);
                    for (int j : bucket[p]) {
                        if (dist[j] == -1) { dist[j] = d+1; q.push(j); }
                    }
                }
            }
        }

        return dist[n-1];
    }
};
