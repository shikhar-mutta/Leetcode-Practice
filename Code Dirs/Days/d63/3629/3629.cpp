// Link: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(maxVal)) SC: O(n + maxVal)
// Approach: BFS with two move types: adjacent step (i +-1, always cost 1),
// and prime teleport (only from an index whose value IS itself prime, to
// any index divisible by that prime). Precompute, for every prime p, the
// list of indices divisible by p (via factorizing each nums[j]). During
// BFS, when popping index i with nums[i] prime, teleport to every index
// in that prime's bucket, then clear the bucket so it's never
// reprocessed (all its indices become reachable together in one shot).
class Solution {
    vector<int> primeFactors(int x) {
        vector<int> factors;
        for (int p = 2; (long long)p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) factors.push_back(x);
        return factors;
    }
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int p = 2; (long long)p * p <= x; p++) if (x % p == 0) return false;
        return true;
    }
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> primeGroup;
        for (int i = 0; i < n; i++) for (int p : primeFactors(nums[i])) primeGroup[p].push_back(i);

        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (i == n - 1) return dist[i];

            if (i > 0 && dist[i-1] == -1) { dist[i-1] = dist[i] + 1; q.push(i-1); }
            if (i < n-1 && dist[i+1] == -1) { dist[i+1] = dist[i] + 1; q.push(i+1); }

            if (isPrime(nums[i])) {
                auto it = primeGroup.find(nums[i]);
                if (it != primeGroup.end()) {
                    for (int j : it->second) {
                        if (dist[j] == -1) { dist[j] = dist[i] + 1; q.push(j); }
                    }
                    primeGroup.erase(it);
                }
            }
        }
        return dist[n-1];
    }
};
